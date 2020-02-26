
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int close_to (double tolerance, double point, double value);
double mag(double ax, double ay, double az);
double fallingEquation (double time);

int main (){
	
	int t;
	double ax, ay, az; 
	int printYesNo = 0;

	int printYesNo2 = 0;
	int waitingDone = 0;
	int waitingTime = 1;
	double fallingDistance;
	
	scanf("%d, %lf, %lf, %lf\n", &t, &ax, &ay, &az);	
	
	
	while(mag(ax, ay, az) < 2){
		if (printYesNo == 0){
			printf("Ok, now I'm receiving data.\n");
			printf("I'm waiting ");
			printYesNo = 1; 
		
		}
		if(t%10 == 0){
			printf(".");
		}
    	scanf("%d, %lf, %lf, %lf\n", &t, &ax, &ay, &az);	
	}
	printf("\n\n");

    int fallingStartingTime = t;	

	while(mag(ax, ay, az) >= 2){
		if(printYesNo2 == 0){
			printf("	help me! I'm falling");
			printYesNo2 = 1;
		}
		if(t%10 == 0){
			printf("!");
		}
		scanf("%d, %lf, %lf, %lf\n", &t, &ax, &ay, &az);	
	}
	printf("\n/n");
	int fallingEndingTime = t;
	
	double fallingMilliSecondsTime = fallingEndingTime - fallingStartingTime;
	double fallingTime = fallingMilliSecondsTime / 1000;
	
	fallingDistance = fallingEquation(fallingTime);
	
	printf("		Ouch! I fell %lf meters in %lf seconds.\n\n", fallingDistance, fallingTime);
	
	return 0;
}

double mag(double ax, double ay, double az){
	double r = sqrt(ax*ax+ay*ay+az*az);
    return r;
}

double fallingEquation (double time){
	double distance;
	distance = .5 * 9.8 * pow(time, 2);
	return distance;	
}



int close_to (double tolerance, double point, double value){
	if(point > value){
		if((point - value) < tolerance){
			return TRUE;
		}
		else {
			return FALSE;
		} 
	}
	else {
		if((value - point) < tolerance){
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
}
