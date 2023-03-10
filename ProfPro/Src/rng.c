/*
 * rng.c
 *
 *  Created on: 7 Oca 2023
 *      Author: metab
 */


#include "rng.h"




void rng_init(){

	//PLL on
	RCC->CR=PLLON;
	//PLL ready flag
	while(!(RCC->CR & PLLREADY)); //PLLREADY hazır olana kadar bekle demek bu.

	//clock
	RNG_CLOCK_ENABLE();

	//1-enable interrupt
	RNG->CR |= IE;

	//2 Rngen bit in the rng_cr
	RNG->CR |= RNGEN;

	//3 seis ve ceis oku
	nvic_irqno_enable(IRQ_HASH_RNG);

}


void HASH_RNG_IRQHandler(void){
	if(((RNG->SR & RNG_CEIS)==0) && ((RNG->SR & RNG_SEIS)==0) && ((RNG->SR & RNG_DRDY)==1))
	{
		//g_random_number = RNG->DR;
		RNG->CR &= ~IE;
		RNG->CR &= ~RNGEN;
		nvic_irqno_disable(IRQ_HASH_RNG);
	}else {//hatalı durum düzeltme

		if((RNG->SR & RNG_CEIS)==1){
			RNG->CR &= ~RNG_CEIS;
		}
		if((RNG->SR & RNG_SEIS)==1){
			RNG->CR &= ~RNG_SEIS;
		}
		//resetle ve yeniden başlat
		RCC->AHB2STR = RNGRST;//resetleme ayarı ama bi alttaki satırdaki gibi tekrar açmazsan kapalı kalır.
		RCC->AHB2STR &= ~RNGRST;
		RNG->CR |= RNGEN;
		RNG->CR |= IE;
	}




}




int64_t get_random_number(){
	rng_init();
	//if(RNG->CR & RNGEN)
	return RNG->DR;
	//return RNG_ERROR;
}
