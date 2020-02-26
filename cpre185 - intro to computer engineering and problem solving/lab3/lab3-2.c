#include <stdio.h>

int main(){
	int integerResult;
	double decimalResult;
	
	integerResult = 6427 + 1725;
	printf("the answer of 6427 + 1725 is %d\n", integerResult);
	
	integerResult = (6971 * 3925) - 95;
	printf("the answer to (6971 * 3925) - 95 is %d\n", integerResult);
	
	decimalResult = 79 + 12/5;
	printf("the answer to 79 + 12/5 is %lf\n", decimalResult);
	
	decimalResult = 3640.0/107.9;
	printf("the answer to 3640.0/107.9 is %lf\n", decimalResult);
	
	integerResult = (22/3)*3;
	printf("the answer to (22/3)*3 is %d\n", integerResult);
	
	integerResult = 22/(3*3);
	printf("the answer to 22/(3*3) is %d\n", integerResult);
	
	decimalResult = 22/(3*3);
	printf("the answer to 22/(3*3) is %lf\n", decimalResult);
	
	decimalResult = (22/3)*3;
	printf("the answer to (22/3)*3 is %lf\n", decimalResult);
	
	decimalResult = (22.0/3)*3.0;
	printf("the answer to (22.0/3)*3.0 is %lf\n", decimalResult);
	
	integerResult = 22/(3*3.0);
	printf("the answer to 22/(3*3.0) is %d\n", integerResult);
	
	decimalResult = 22.0/3.0*3.0;
	printf("the answer to 22.0/3.0*3.0 is %lf\n", decimalResult);
	 
	decimalResult = 3.14*(23.567/2)*(23.567/2);
	printf("the area of a circle with a diameter of 23.567 is %lf\n", decimalResult);
	// I googled the equation of a circle and just re-rearrange it to fit the needed specifications that I knew would work.
	decimalResult = .3048 * 14;
	printf("the number of meters in 14 feet, is %lf\n", decimalResult);
	// I just plugged in the equation with the variable.
	decimalResult = (76 - 32)/1.8;
	printf("76 degrees in Fahrenheit is %lf centigrade\n", decimalResult);
	//same principle as the last equation.
return 0;
}