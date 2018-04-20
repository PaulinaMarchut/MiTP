#include <LPC21xx.H>

#include "led.h"

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

enum StepDir {STEP_LEFT,STEP_RIGHT};

void LedInit(void){	
	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;	
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;

	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
		default:
			break;
	}
}

void LedStep(enum StepDir eStepDirection){
	static unsigned int uiLightPosition;

	if(eStepDirection == STEP_LEFT){
			uiLightPosition = (uiLightPosition+1) % 4;
	}
	else if(eStepDirection == STEP_RIGHT){
		uiLightPosition = (uiLightPosition-1) % 4;
	}
	LedOn(uiLightPosition);
}

void LedStepLeft(void){
	LedStep(STEP_LEFT);
}

void LedStepRight(void){
	LedStep(STEP_RIGHT);
}
