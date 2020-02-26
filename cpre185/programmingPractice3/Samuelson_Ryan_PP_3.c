/* 	Ryan Samuelson
	rws15@iastate.edu
	CPRE 185 Section g
	Programming Practice 3
 <Reflection 1 What were you trying to learn or achieve?>
		In this programming practice, I achieved my goals with the while the while loops. 
		My goal was to improve my skills on forming loops, either "while" or "for" loops. 
<Reflection 2 Were you successful? Why or Why not?>
		In my first draft of the "int main" function I didn't include the "askForNumber" function.
		While I was trying to revise tried to add more fluid trasistion after a wrong number was enterd.
<Reflection 3 Would you do anything differently if starting this program over? If so, explain what.>
		if I restarted this process I wouldn't do anything different. I would, how ever choose a more interesting 
		topic to write some code about.
<Reflection 4 Think about the most important thing you learned when writing this piece of code. What was it and explain why it was significant.>
		the most improtant thing i learned in this was program was how to "sanity check" my code. during my running of the code, i found 
		that my code compiled fine but wouldn't run. though many uses of "printf" functions i found that my "scanf" function was not correct.
<Other questions/comments for Instructors>
	(optional)
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isInvalidNumber (int trueFalse);
int numCounter (int num1);
int askForNumber();

int main(){
	int x;
	x = askForNumber();
	while (isInvalidNumber(x) == FALSE){
   	    x = askForNumber();
	}
	numCounter(x);
	return 0;
}

int askForNumber(){
	int y;
	printf("Choose a number from 1-20: ");
	scanf("%d", &y);
	return y;
}

int isInvalidNumber (int trueFalse){
	if(trueFalse > 20){
		printf("Your number is too high, please pick a different number\n");
		return FALSE;
	}
	else if (trueFalse < 0){
		printf("Your number is too low, please pick a different number\n");
		return FALSE;
	}
	else{
		return TRUE;
	}
	
}

int numCounter (int num1){
	while(num1 >= 0){
		printf("%d\n", num1);
		num1--;
	}
	return;
}	 