#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.141592653589

double roll(double x_mag);
int scaleRadsForScreen(double rad);
void print_chars(int num, char use);
void graph_line(int number);


int main(){
	graph_line(20);

	return 0;
}
void print_chars(int num, char use){
	int i;
	if(use == 'r'){
		printf("%40c", "0");
		for(i = 0; i < (num - 40); i++){
			printf("%c", &use);
		}
	}
	else if(use == 'l'){
		for(i = 0; i < (40 - num); i++){
			printf("%c", "0");
		}
		for(i = 0; i < num; i++){
			printf("%c", &use);
		}
	}
	else if(use == '0'){
		printf("%40c", "0");
		printf("0");
	}
}

	
//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number){
	char catx;
	int finalNum = number + 39;
	
	if(finalNum < 40){
		catx = 'l';
	}
	if(finalNum > 40){
		catx = 'r';
	}
	if(finalNum == 40){
		catx = '0';
	}
	print_chars(finalNum, catx);
}

int scaleRadsForScreen(double rad){
	double value = rad / (PI / 2);
	int ReturedValue = value * 39;
}
	