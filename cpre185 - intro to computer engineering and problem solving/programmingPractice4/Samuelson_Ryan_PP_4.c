/* 	
	Ryan Samuelson	
	rws15@iastate.edu
	CPRE 185 Section g
	Programming Practice 4
 	<Reflection 1 What were you trying to learn or achieve?>
	In this Programming practice i tried to improve my knolage with arrays and pointers.
	<Reflection 2 Were you successful? Why or Why not?>
	For the most part i was successful, the one thing i didnt figure out was how to return a mulidementional
	array from a function. i still dont know how to do that, or if its even possible.
	<Reflection 3 Would you do anything differently if starting this program over? If so, explain what.>
	yes, i would go about the double array differently. I would declare the mulidementional array and not try to concatenate to create the array.
	<Reflection 4 Think about the most important thing you learned when writing this piece of code. What was it and explain why it was significant.>
	The most important thing i learned in this assignment was how to pass functions and pointers in to function and correctly use them. its significant because, the use of pointers are very prominate
	in c because its the only way to return more than one value from a function.
	<Other questions/comments for Instructors>
	Answer here (optional)
*/

#include <stdio.h>
#include <math.h>
#define MAX 100

void fillArray(int length);
void copyArray(int length);
int array1[MAX];
int array2[MAX];
int array3[2][MAX];

int main(){
	
	int length;
	int i, k;
	
	printf("length of array: ");
	scanf("%d", &length);
	
	fillArray(length);
	copyArray(length);
	int j;
	

	for(j = 0; j < length; j++){
	printf("the original value in the array was: %d and the squared value is %d\n", array3[0][j], array3[1][j]);
	}
	
	return 0;
}

void fillArray(int length){
	int y;
    int i;
    
    for (i = 0; i < length; i++) {
        printf("enter a number:");
        scanf("%d", &y);
        printf("\n");
        array1[i] = y;
    }
}

void copyArray(int length){
	int i, k;
	for(i = 0; i < length; i++){
		k =  array1[i];
		array2[i] = k * k;
		array3[0][i] = array1[i];
		array3[1][i]= array2[i];
	}
}
