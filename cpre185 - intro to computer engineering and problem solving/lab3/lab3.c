// CprE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main()
{
	int integerResult;
	double decimalResult;
	
	integerResult = 77 / 5;
	printf("The value of 77/5 is %d\n", integerResult);
	// the line above didn't have the correct data-type.
	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n", integerResult);
	// the printf line above didn't have a specifier
	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %lf\n", decimalResult);
	// the line above didn't have the correct data-type.
	return 0;
}

