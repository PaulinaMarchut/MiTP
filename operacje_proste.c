#include <LPC21xx.H>
#include "operacje_proste.h"

#define NULL 0

enum CompResult{DIFFERENT,EQUAL};

void CopyString(char pcSource[], char pcDestination[]){
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter = 0; pcSource[ucCharacterCounter] != NULL; ucCharacterCounter++){
		pcDestination[ucCharacterCounter] = pcSource[ucCharacterCounter];
	}
	pcDestination[ucCharacterCounter] = NULL;
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter = 0; pcStr1[ucCharacterCounter] != NULL; ucCharacterCounter++){
		if(pcStr2[ucCharacterCounter] != pcStr1[ucCharacterCounter]){
			return DIFFERENT;
		}
	}
	if(pcStr2[ucCharacterCounter] != NULL){
		return DIFFERENT;
	}
	return EQUAL;
}

void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	unsigned char ucStrLength;
	for(ucStrLength = 0; pcDestinationStr[ucStrLength] != NULL; ucStrLength++){}
	CopyString(pcSourceStr,pcDestinationStr+ucStrLength);
}

void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter = 0; pcString[ucCharacterCounter] != NULL; ucCharacterCounter++){
		if(pcString[ucCharacterCounter] == cOldChar){
			pcString[ucCharacterCounter] = cNewChar;
		}
	}
}

