/* 	Ryan Samuelson
	rws15@iastate.edu
	CPRE 185 Section G
Programming Practice 2 
<Reflection 1 What were you trying to learn or achieve?>
	I was tring to grasp how functions worked so i can get more practice with them. I was not able to 
	finish the code and make it work without some outside resource.
	
<Reflection 2 Were you successful? Why or Why not?>
	yes, I was able to get it done. It was not hard with the simple things like, printf, and scanf. 
	The funtions still gave me some problems and the functions are what the outside resource help me with.
	
<Reflection 3 Would you do anything differently if starting this program over? If so, explain what.>
	yes i would, before i started i didnt read what was suppose to in my code. later, after i finished most of the code, i then read the rubric
	adn then tried to change my pre-exsiting code to fit the rubric. next time i need to read the rubric first to see what is going in the code.

<Reflection 4 Think about the most important thing you learned when writing this piece of code. What was it and explain why it was significant.>
	the most important thing i learned in writing this code was figuring out how to pull in peramiters and return a statement of a varuable.
	
<Other questions/comments for Instructors>
	does using more than 2 "if" statements get me more bonus points?
*/
#include <stdio.h>
int main() {
	
	double num3 = 0;
	void minMax(double num3);
	
	printf("Choose a number from 1-50: ");
	scanf("%lf", &num3);
	printf("Your number %2.0lf, ", num3);
	minMax(num3);
			
return 0;
}

void minMax(double _num3){
	int num1 = 24;
	int num2 = 26;
	
	if(_num3 <= num1){
		printf("is less than half of the max number.\n");
	}
	if(_num3 == 25){
		printf("is half of the max.\n");
	}
	if(_num3 >= num2){
		printf("is more than half of the max number.\n");
	}
}