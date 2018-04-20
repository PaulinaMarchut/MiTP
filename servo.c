#include "servo.h"
#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

#define DETECTOR_OUT_bm (1<<10)

enum DetectorState{ACTIVE,INACTIVE};

enum ServoState{CALLIB,IDLE,IN_PROGRESS};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};

struct Servo sServo;

void DetectorInit(void){
	IO0DIR = IO0DIR & ~DETECTOR_OUT_bm;
}

enum DetectorState eReadDetector(void){
	if((IO0PIN & DETECTOR_OUT_bm) == 0){
		return INACTIVE;
	}
	else{
		return ACTIVE;
	}
}


void Automat(void){
	switch(sServo.eState){
			case IDLE:
				if (sServo.uiCurrentPosition == sServo.uiDesiredPosition){
					sServo.eState = IDLE;
				}
				else{
					sServo.eState = IN_PROGRESS;
				}				
				break;
			case IN_PROGRESS:
				if (sServo.uiCurrentPosition == sServo.uiDesiredPosition){
					sServo.eState = IDLE;
				}
				else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition){
					sServo.eState = IN_PROGRESS;
					LedStepLeft();
					sServo.uiCurrentPosition--;
				}
				else if(sServo.uiCurrentPosition < sServo.uiDesiredPosition){
					sServo.eState = IN_PROGRESS;
					sServo.uiCurrentPosition++;
					LedStepRight();
				}
				break;
			case CALLIB:
				if(eReadDetector() == INACTIVE){
					sServo.eState = IDLE;
					sServo.uiCurrentPosition = 0;
				}
				else{
					LedStepLeft();
				}
			
			default:
				break;
		}
}

void ServoInit(unsigned int uiServoFrequency){
	LedInit();
	sServo.eState = CALLIB;
	sServo.uiDesiredPosition = 0;
	Timer0Interrupts_Init(1000000/uiServoFrequency,&Automat);
}

void ServoCallib(void){
	sServo.eState = CALLIB;
	sServo.uiDesiredPosition = 0;
}

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition = uiPosition;
}

void ServoStep(void){
	sServo.uiDesiredPosition = sServo.uiDesiredPosition + 12;
}
