#include "konwersje.h"

#define NULL 0
#define MAX_TOKEN_NR 3
#define MAX_KEYWORD_STRING_LTH 10
#define MAX_KEYWORD_NR 3


typedef enum TokenType{KEYWORD,NUMBER,STRING} TokenType;
typedef enum KeywordCode{LD,ST,RST} KeywordCode;
typedef enum State{TOKEN,DELIMITER} State;

typedef struct Keyword{
	
	KeywordCode eCode;
	char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

typedef union TokenValue{
	
	KeywordCode eKeyword;
	unsigned int uiNumber;
	char *pcSting;
} TokenValue;


typedef struct Token{
	
	TokenType eType;
	TokenValue uValue;
	
	
} Token;

Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;

Keyword asKeywordList[MAX_KEYWORD_NR]=
{
	{RST,"reset"},
	{LD,"load"},
	{ST,"store"}
};

unsigned char ucFindTokenInString(char *pcString){
	
	unsigned char ucCharCounter;
	unsigned char ucTokenCounter = 0;
	char cCurrentCharacter;
	State eState = DELIMITER;

	for(ucCharCounter = 0;;ucCharCounter++){
		
		switch(eState){
			case TOKEN:
				if((ucTokenCounter == MAX_TOKEN_NR) || (cCurrentCharacter == NULL)){
					return ucTokenCounter;
				}
				else if(cCurrentCharacter ==' '){
					eState = DELIMITER;
				}
				else{
					eState = TOKEN;
				}
				break;								
			case DELIMITER:
				if(cCurrentCharacter == NULL){
						return ucTokenCounter;
				}
				else if(cCurrentCharacter == ' '){
					eState = DELIMITER;
				}
				else{
					asToken[ucTokenCounter].uValue.pcSting = pcString + ucCharCounter;
					ucTokenCounter++;
					eState = TOKEN;
				}
				break;	
		}
	}
}

enum Result eStringToKeyword(char pcStr[],KeywordCode *peKeywordCode){
	
	
}




