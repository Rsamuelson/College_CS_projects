#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int close_to (double tolerance, double point, double value);
double mag(double ax, double ay, double az);
double fallingEquation (double time);
double vi(double v_minus_1, double g, double acc, double t, double t_minus1);
double xi(double x_minus_1, double vi, double t, double t_minus1);


int main (){
	
	int t;
	int t_minus_1 = 0;
	int printYesNo = 0;
	int printYesNo2 = 0;
	int waitingDone = 0;
	int waitingTime = 1;
	double gravity = 9.8;
	double fallingDistance;
	double xTotal = 0;
	double tmp_x_minus_1 = 0;
	double tmp_v_minus_1 = 0;
	double ax, ay, az; 
	
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
		t_minus_1 = t;
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
		t_minus_1 = t;		
		scanf("%d, %lf, %lf, %lf\n", &t, &ax, &ay, &az);
		
		double tmp_vi = vi(tmp_v_minus_1, gravity, mag(ax, ay, az), t, t_minus_1);
		tmp_v_minus_1 = tmp_vi;
		double tmp_xi = xi(tmp_x_minus_1, tmp_vi, t, t_minus_1);
		tmp_x_minus_1 = tmp_xi;
		xTotal += tmp_xi;
	}
	printf("\n\n");
	int fallingEndingTime = t;
	
	double fallingMilliSecondsTime = fallingEndingTime - fallingStartingTime;
	double fallingTime = fallingMilliSecondsTime / 1000;
	
	fallingDistance = fallingEquation(fallingTime);
	
	printf("		Ouch! I fell %lf meters in %lf seconds.\n\n", fallingDistance, fallingTime);
	printf("Compensating for air resistance, the fall was %lf meters.\n", xTotal);
	double percentFallingAir = (xTotal / fallingDistance) * 100;
	printf("This is %d% less than computed before.", percentFallingAir);
	return 0;
}

double vi(double v_minus_1, double g, double acc, double t, double t_minus1) {
    return v_minus_1 + (g - acc * 9.8) * (t - t_minus1);	
}

double xi(double x_minus_1, double vi, double t, double t_minus1) {
    return x_minus_1 + vi * (t - t_minus1);	
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
