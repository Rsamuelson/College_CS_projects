// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	int True;
	int False;
	if(*Button_LEFT ==  1){
		return True;
	}
	else{
		return False;
	}
}
// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag){
	if(x_mag > 1){
		x_mag = 1;
	}
	else if (x_mag < -1){
		x_mag = -1;
	}
	double x_rad_value = asin(x_mag);
	return x_rad_value;
}
	

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag){
	if(y_mag > 1){
			y_mag = 1;
		}
		else if (y_mag < -1){
			y_mag = -1;
		}
		double y_rad_value = tan(y_mag);
		return y_rad_value;
}

// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad){
	int value = rad / (PI / 2);
	int ReturedValue = value * 39;
	return ReturedValue;
}
	

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
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

int main(){
	double *x, *y, *z;			// magnitude values of x, y, and z accelerations
	int *b_Up, *b_Down, *b_Left, *b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	
	//insert any beginning needed code here
	int true;
	int *t;
	

	do
	{
		// Get line of input
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", t, x, y, z, b_Up, b_Down, b_Left, b_Right);
		
			// calculate roll and pitch
			pitch_rad = pitch(*y);
			roll_rad = roll(*x);
			
			// switch between roll and pitch(up vs. down button) 
			double *final = &roll_rad;
			double *swap1 = &pitch_rad;
			if(*b_Down == 1){			
				double temp = *final;
				*final = *swap1;
				*swap1 = temp;
			}						
			
			// Scale your output value
			int scaled_value = scaleRadsForScreen(*final);

			// Output your graph line
			graph_line(scaled_value);
		
		fflush(stdout);
	} while (read_acc(x, y, z, t, b_Up, b_Down, b_Left, b_Right) == true); // Modify to stop when left button is pressed
	return 0;
}
