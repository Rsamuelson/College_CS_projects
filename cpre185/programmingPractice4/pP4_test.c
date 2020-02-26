#include <stdio.h>

#define MAX 100

void fillArray(int length, int* array1);
double arraySqr(int* array1, int* array3, int* length);
void arrayPrint(int* array3, int length);

int main(){
	
	int* array1[MAX];
	int* array2[MAX];
	int* array3[MAX];
	int length;
	
	printf("length of array: ");
	scanf("%d", &length);

	fillArray(length, *array1);
	arraySqr(*array1, *array3, length);
	arrayPrint(*array3, length);
	
	return 0;
}


/* int main() {
   int x;
   int i;
   int array1[100];
     
   printf("enter a length:");
   scanf("%d", &x);

  
   fillArray(x, array1);
   for (i = 0; i < x; i++) {
       printf("%d\n", array1[i]);
   }
   return 0;
}
*/

void fillArray(int length, int* array1) {
    int y;
    int i;
    
    for (i = 0; i < length; i++) {
        printf("enter a number:");
        scanf("%d", &y);
        printf("\n");
        array1[i] = y;
    }
}

double arraySqr(int* array1, int* array3, int length){
	int i, k;
	strcpy(array2, array1); 
	for(i = 0; i < length; i++){
		k =  array[i];
		array2[i] = k * k;
	}
	
	return 0;
}

void arrayPrint(int* array3, int length){
	int i;
	for (i = 0; i < ; i++) {
		   printf("%d\n", array3[i]);
	   }
}