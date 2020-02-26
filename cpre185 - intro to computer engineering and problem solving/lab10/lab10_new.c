// Lab 10 ExTalker Skeleton Code

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

// reads words from the file
// into wl and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s);

//my functions
void draw_character(int x, int y, char use)
void printAvatar();
void moveleft();
void moveRight();
void moveUp();
void moveDown();
int canIMoveLeft();
int canIMoveRight();
int canIMoveUp();
int canIMoveDown();

int currentX, currentY;

char *printingArray[MAXWORDS];
int printingArrayNum = 0;
int currentLineX = 0;

int main(int argc, char* argv[]){
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;
	wordCount = readWords(wordlist, argv[1]);

	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%15s,", wordlist[i]);

			}
		printf("\n");
		}

// most of your code goes here. Don't forget to include the ncurses library 

//print words
	
	int x, y, wordVar = 0;
	
	currentX = 3;
	currentY = 0;
	currentLineX = 0;
	
	wordCount = readWords(wordlist, argv[1]);
	
	initscr();
	
	for(y = 0; y < 16; y++){
		for(x = 0; x < 60; x + 15){
			draw_choosing_words(x, y, wordlist[wordVar]);
			wordVar ++;
		}
	}
	refresh();
	
	printAvatar();
	
	int time, leftJoyStick, rightJoyStick, upJoyStick, downJoyStick, joyStickButton, upButton, downButton, leftButton, rightButton;	
	scanf();
	
	do{
		if(time%50){
			if(leftJoyStick == 1){
				if(canMoveLeft() == 1){
					moveleft();
				}
			}
			if(rightJoyStick == 1){
				if(canMoveRight() == 1){
				moveRight();
				}
			}
			if(upJoyStick == 1){
				if(canMoveUp() == 1){
				moveUp();
				}
			}
			if(downJoyStick == 1){
				if(canMoveDown() == 1){				
				moveDown();
				}
			}
			
			//line is at max 80 charaters (x = 18)
			
			if(upButton == 1){
				//choose word with a space
				chooseWordWithSpace(*wordlist);
				printPrintingArray();
			}
			if(leftButton == 1){
				//append word without space
				chooseWordWithoutSpace(*wordlist);
				printPrintingArray();
			}
			if(downButton == 1){
				//remove the last word (like an "undo" button)
				removeWord();
				printPrintingArray();
			}
			if(rightButton == 1){
				//capitalize the first letter of the next word (optional)
			}
			if(joyStickButton == 1){
				//starts a new sentance, and clears the line
				clearLine();
				printPrintingArray();
			}
		}
		refresh();
		scanf();
	}while(1);

	getch();
	endwin();
	
    return 0;
	}

// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {
	int len = strlen(s) ;
	int x;
	if (len ==0) return;
	x = len-1;
	while (isspace(s[x]) && (x>=0)) {
			s[x] = '\0';
			x--;
			}
	}

// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
	
void draw_character(int x, int y, char use){
	mvaddch(y,x,use);    
	refresh();
}

void draw_choosing_words(int x, int y, char word[]){
	mvprintw(y, x, "%15s", word);
}

void printAvatar(){
	draw_character(currentX, currentY, AVATAR);
}

int canIMoveLeft(){
	if(currentX == 3){
		return 0;
	}
	return 1;
}

int canIMoveRight(){
	if(currentX == 63){
		return 0;
	}
	return 1;
}

int canIMoveUp(){
	if(currentY == 0){
		return 0;
	}
	return 1;
}

int canIMoveDown(){
	if(currentY = 16){
		return 0;
	}
	return 1;
}

void moveLeft(){
	draw_character(currentX , currentY, EMPTY_SPACE);
	currentX = currentX - 15;
	draw_character(currentX , currentY, AVATAR);
}

void moveRight(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentX = currentX + 15;
	draw_character(currentX, currentY, AVATAR);
}

void moveDown(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentY = currentY + 1;
	draw_character(currentX, currentY, AVATAR);
}

void moveUp(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentY = currentY - 1;
	draw_character(currentX, currentY, AVATAR);
}

void chooseWordWithSpace(char* wordlist[]){
	int i = (currentY * 5) + currentX;
	*printingArray[printingArrayNum] = EMPTY_SPACE;
	printingArrayNum ++;
	*printingArray[printingArrayNum] = *wordlist[i];
	printingArrayNum ++;
}

void chooseWordWithoutSpace(char* wordlist[]){
	int i = (currentY * 5) + currentX;
	*printingArray[printingArrayNum] = *wordlist[i];
	printingArrayNum ++;
}

void removeWord(){
	*printingArray[printingArrayNum] = NULL;
	printingArrayNum--;
}

void clearLine(){
	int i;
	for(i = 0; i < printingArrayNum; i++){
		printingArray[i] = NULL;
	}
}

void printPrintingArray(){
	int i;
	for(i = 0; i < printingArrayNum; i++){
		while(x > 80){
			mvprintw(18, currentLineX + strlen(printingArray[printingArrayNum]), "%s", printingArray[printingArrayNum]);
			currentLineX = currentLineX + strlen(printingArray[printingArrayNum]);
			refresh();
		}
	}
}
