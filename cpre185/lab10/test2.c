
#define WORDLENGTH 11
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0  // set to 0 to disable debug output
#define AVATAR '*'
#define EMPTY_SPACE ' '

int main(){
	char *string[MAXWORDS];
	char *printString[MAXWORDS];
	int x;
	for(x = 0; x < 5; x++){
		printf("word for string: ");
		scanf("%s", string);
	}
	printf("final Phrase: ");
	for(x = 0; x < 5; x++){
		printf("%s", string);
		
	}
	return 0;
}