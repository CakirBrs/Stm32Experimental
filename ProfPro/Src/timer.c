/*
 * timer.c
 *
 *  Created on: 12 Oca 2023
 *      Author: metab
 */
#include "timer.h"

TIM_RegDef_t * timTab[]={TIMER1,TIMER2,TIMER3,TIMER4,TIMER5,TIMER6,TIMER7,TIMER8};

static timer_clock_enable(TIM_RegDef_t * pTimerX){
	if(pTimerX==TIMER1)
		TIMER1_CLOCK_ENABLE();
		else if(pTimerX==TIMER8)
			TIMER8_CLOCK_ENABLE();
		else if(pTimerX==TIMER9)
			TIMER9_CLOCK_ENABLE();
		else if(pTimerX==TIMER10)
			TIMER10_CLOCK_ENABLE();
		else if(pTimerX==TIMER11)
			TIMER11_CLOCK_ENABLE();
		else if(pTimerX==TIMER2)
			TIMER2_CLOCK_ENABLE();
		else if(pTimerX==TIMER3)
			TIMER3_CLOCK_ENABLE();
		else if(pTimerX==TIMER4)
			TIMER4_CLOCK_ENABLE();
		else if(pTimerX==TIMER5)
			TIMER5_CLOCK_ENABLE();
		else if(pTimerX==TIMER6)
			TIMER6_CLOCK_ENABLE();
		else if(pTimerX==TIMER7)
			TIMER7_CLOCK_ENABLE();
	}


void timer_init(TIMNO e_timer_no, unsigned prescaler, unsigned period, unsigned repeat){

	//clock enable
	timer_clock_enable(timTab[e_timer_no]); // timer çevreselin clocku

	//APB2 ve APB1 hatları (timer 1,8,9,10,11)

	TIM_RegDef_t *p= timTab[e_timer_no];
	p->ARR=period-1;
	p->PSC=prescaler-1;

	p->CNT=0;
	p->CR1 |= (1U<<0); //timer enable


}

void timer_reset(TIMNO e_timer_no){
	TIM_RegDef_t *p= timTab[e_timer_no];
	p->CNT=0;
}
void timer_start(TIMNO e_timer_no, int bstart_stop){
	TIM_RegDef_t *p= timTab[e_timer_no];
	if(bstart_stop==TIMER_START)
		p->CR1 |=(1U<<0);
	else if(bstart_stop==TIMER_STOP)
		p->CR1 &= ~(1U<<0);
}

