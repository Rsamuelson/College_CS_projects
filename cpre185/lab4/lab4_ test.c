/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
	double mag(double ax, double ay, double az);
	double minutes(double inMs);
	double seconds(double inMs);
	double millis(double inMs);

int main(void) {
	double t;
	double ax, ay, az; 	
	
	while (TRUE) {
		scanf("%lf,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", t/1000, ax, ay, az);

 /*	CODE SECTION 1 */
		printf("At %9.0lf ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az));
/* 	CODE SECTION 2 */
		printf("At %6.0lf minutes, %2.0lf seconds, and %3.0lf milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

	}

return 0;
}

/* Put your functions here */
	double mag(double ax, double ay, double az){
		sqrt(ax*ax+ay*ay+az*az);
	return;
	}
	
	double minutes(double inMs){
	    int min = inMs /(1000 * 60);
		return (double)min;
	}
	
	double seconds(double inMs){
	    int wholeMin = inMs /(1000 * 60);
	    double remainMSecs = inMs - (wholeMin * 1000 * 60);
		int secs = remainMSecs / 1000;
		return secs;
	}
	
	double millis(double inMs){
	    int wholeMin = inMs /(1000 * 60);
	    double remainMSecs = inMs - (wholeMin * 1000 * 60);
		int secs = remainMSecs / 1000;
		double remainMil = remainMSecs - (secs * 1000);
		return remainMil;
	} 