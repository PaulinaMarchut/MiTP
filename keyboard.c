#include <LPC21xx.H>
#include "keyboard.h"

#define Butt1_bm (1 << 4)
#define Butt2_bm (1 << 6)
#define Butt3_bm (1 << 5)
#define Butt4_bm (1 << 7)
#define BUTTONS_bm 0x000000F0

void KeyboardInit(void){
	IO0DIR = IO0DIR & ~(Butt1_bm | Butt2_bm | Butt3_bm | Butt4_bm);
}

enum ButtonState eKeyboardRead(void){
	if((IO0PIN & Butt1_bm) == 0){
		return BUTTON_1;
	}
	else if((IO0PIN & Butt2_bm) == 0){
		return BUTTON_2;
	}
	else if((IO0PIN & Butt3_bm) == 0){
		return BUTTON_3;
	}
	else if((IO0PIN & Butt4_bm) == 0){
		return BUTTON_4;
	}
	else {
		return RELASED;
	}
	
}
