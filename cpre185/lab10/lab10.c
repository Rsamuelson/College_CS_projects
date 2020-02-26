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

char *printingArray[MAXWORDS];
int printingArrayNum = -1;
int currentLineX = 0;
int currentX, currentY;
char* wordlist[MAXWORDS];
int wordCount;

//modifies s to trim white space off the right side
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

// reads words from the file
// into wl and trims the whitespace off of the end
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

//my functions
void draw_character(int x, int y, char use){
	mvaddch(y, x * 15, use);    
	refresh();
}

void draw_choosing_words(int x, int y, char* wordlist[MAXWORDS], int wordVar){
	mvprintw(y, x, "%15s", wordlist[wordVar]);
}

void printAvatar(){
	draw_character(currentX, currentY, AVATAR);
}

void moveLeft(){
	draw_character(currentX , currentY, EMPTY_SPACE);
	currentX = currentX - 1;
	draw_character(currentX , currentY, AVATAR);
}

void moveRight(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentX = currentX + 1;
	draw_character(currentX, currentY, AVATAR);
}

void moveUp(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentY = currentY - 1;
	draw_character(currentX, currentY, AVATAR);
}

void moveDown(){
	draw_character(currentX, currentY, EMPTY_SPACE);
	currentY = currentY + 1;
	draw_character(currentX, currentY, AVATAR);
}

int canMoveLeft(){
	if(currentX == 0){
		return 0;
	}
	return 1;
}

int canMoveRight(){
	if(currentX == 5){
		return 0;
	}
	return 1;
}

int canMoveUp(){
	if(currentY == 0){
		return 0;
	}
	return 1;
}

int canMoveDown(){
	if(currentY = 16){
		return 0;
	}
	return 1;
}

void chooseWordWithSpace(char* wordlist[MAXWORDS]){
	int i = (currentY * 5) + currentX;
	printingArrayNum ++;
	printingArray[printingArrayNum]  = strcat(wordlist[i], " ");
}


void chooseWordWithoutSpace(char* wordlist[MAXWORDS]){
	int i = (currentY * 5) + currentX;
	printingArrayNum++;
	printingArray[printingArrayNum]  = wordlist[i];
}

void removeWord(){
	if(printingArrayNum > 0){
		printingArrayNum--;
	}
}

void clearLine(){
		printingArrayNum = -1;
}

void printPrintingArray(){
	int i;
	int x = 0;
	if(printingArrayNum == -1){
		mvprintw(18, 0, "%80s", EMPTY_SPACE);

	}
	for(i = 0; i <= printingArrayNum; i++){
		mvprintw(18, x, "%s", printingArray[i]);
		x = x + strlen(printingArray[i]);
		refresh();
	}
}

int main(int argc, char* argv[]){

	int i;
	if (DEBUG) {
		printf("Read %d words from %s \n",wordCount, argv[1]);
		for (i = 0; i< wordCount; i++) {
			printf("%15s", wordlist[i]);

			}
		printf("\n");
		}

// most of your code goes here. Don't forget to include the ncurses library 

//print words
	
	int x, y, wordVar = 0;
	
	currentX = 0;
	currentY = 0;
	currentLineX = 0;
	
	wordCount = readWords(wordlist, argv[1]);
	
	
	initscr();
	refresh();

	x = 0;
	y = 0;
	for(wordVar = 0; wordVar < wordCount; wordVar++) {
         draw_choosing_words(x, y, wordlist, wordVar);
		 x = x + 15;
		 if (x > 65) {
			 y = y +1;
			 x = 0;
		 }
	}

	refresh();
	
	printAvatar();
	
	int time, downButton, upButton, leftButton, rightButton, joyStickButton, slider, downJoyStick, upJoyStick, leftJoyStick, rightJoyStick, xJoy, yJoy = 0;	
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &downButton, &upButton, &leftButton, &rightButton, &joyStickButton, &slider ,&downJoyStick, &upJoyStick, &leftJoyStick, &rightJoyStick, &xJoy, &yJoy);
	//time = 500;
	// rightJoyStick = 0;
	// leftButton = 0;
	//upButton = 1;
	// downButton = 0;
	// rightButton = 0;
	// joyStickButton = 0;
	do{
		if(time%250 == 0){
		
			if(leftJoyStick == 1){
				if(canMoveLeft() == 1){
					moveLeft();
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
				chooseWordWithSpace(wordlist);
				printPrintingArray();
			}
			if(leftButton == 1){
				//append word without space
				chooseWordWithoutSpace(wordlist);
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
		//rightJoyStick = 0;
		// upButton = 0;
		// time = 1;
		refresh();
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &downButton, &upButton, &leftButton, &rightButton, &joyStickButton, &slider ,&downJoyStick, &upJoyStick, &leftJoyStick, &rightJoyStick, &xJoy, &yJoy);
	}while(1);

	
	endwin();
	
    return 0;
}
