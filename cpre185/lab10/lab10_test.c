// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output
#define AVATAR "*"

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


void draw_choosing_words(int x, int y, char* wordlist[MAXWORDS], int wordVar){
	mvprintw(y, x, "%15s", wordlist[wordVar]);
}

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordCount;
	int x, y;
	wordCount = readWords(wordlist, argv[1]);
	initscr();
	refresh();
	int wordVar = 0;
	for(y = 0; y < 16; y++){
		for(x = 0; x < 60; x + 15){
			draw_choosing_words(x, y, wordlist, wordVar);
			wordVar ++;
		}
	}
	refresh();
	endwin();
//moving the avatar with joystick and choosing the word
	
    return 0;
	}


