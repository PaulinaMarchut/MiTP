#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"
#include "servo.h"
#include "uart.h"

extern char cOdebranyZnak;

int main (){
	
	KeyboardInit();
	ServoInit(200);
	UART_InitWithInt(9600);

	

	while(1){
		if((eKeyboardRead() == BUTTON_1) | (cOdebranyZnak == 'c')){
			ServoCallib();
			cOdebranyZnak = 0;
		}
		else if(eKeyboardRead() == BUTTON_2){
			ServoGoTo(12);
		}
		else if(eKeyboardRead() == BUTTON_3){
			ServoGoTo(24);
		}
		else if(eKeyboardRead() == BUTTON_4){
			ServoGoTo(36);
		}
		else if(cOdebranyZnak == '1'){
			ServoStep();
			cOdebranyZnak = 0;
		}
	 	
		
	}
}
