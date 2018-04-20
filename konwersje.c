#include <LPC21xx.H>

#define NULL 0
#define TETRADE_bm 0x000F

enum Result{OK,ERROR};

void UIntToHexStr(unsigned int uiValue, char pcStr[]){
	unsigned char ucTetradeCounter;
	unsigned char ucCurrentTetrade;
	pcStr[0] = '0';
	pcStr[1] = 'x';
	pcStr[6] = NULL;
	for(ucTetradeCounter = 0; ucTetradeCounter <= 3; ucTetradeCounter++){
		ucCurrentTetrade = TETRADE_bm & ( uiValue >> (4 * ucTetradeCounter));
		if(ucCurrentTetrade <= 9){
			pcStr[5 - ucTetradeCounter] = ucCurrentTetrade + '0';
		}
		else{
			pcStr[5 - ucTetradeCounter] = ucCurrentTetrade + 'A';
		}	
	}
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	unsigned char ucCharCounter;
	char cCurrentChar;
	if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL)){
		return ERROR;
	}
	*puiValue = 0;
	for(ucCharCounter = 2;ucCharCounter < 7;ucCharCounter++){
		cCurrentChar = pcStr[ucCharCounter];
		if(cCurrentChar == NULL){
			return OK;
		}
		else if((cCurrentChar >= 'A') && (cCurrentChar <= 'F')){
			cCurrentChar = cCurrentChar - 'A' + 10;
		}
		else if((cCurrentChar >= 'a') && (cCurrentChar <= 'f')){
			cCurrentChar = cCurrentChar - 'a' + 10;
		}
		else if((cCurrentChar >= '0') && (cCurrentChar <= '9')){
			cCurrentChar = cCurrentChar - '0';
		}
		else{
			return ERROR;
		}
		*puiValue = *puiValue << 4;
		*puiValue = *puiValue + cCurrentChar;
	}
	return ERROR;
}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	unsigned char ucCharCounter;
	for(ucCharCounter=0;pcDestinationStr[ucCharCounter] != NULL;ucCharCounter++){}
	UIntToHexStr(uiValue,pcDestinationStr + ucCharCounter);
}
