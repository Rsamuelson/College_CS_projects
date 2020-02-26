#include <stdio.h>


#define MAXPOINTS 10000

double avg(double buffer[], int num_items);

int main(int argc, char* argv[]) {
	int string[5] = { 1, 2, 3, 4, 5};
	
	avg(string[5], 5);
	return 0;
}
double avg(double buffer[], int num_items){
	double averageNum = 0;
	int i;
	
	for(i = 0; i < num_items; i++){
		averageNum = buffer[i] + averageNum;
	}
	return averageNum;
}