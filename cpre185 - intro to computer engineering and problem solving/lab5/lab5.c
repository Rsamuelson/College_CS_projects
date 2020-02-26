/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

	int close_to (double tolerance, double point, double value);
	double mag(double ax, double ay, double az);
	
int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
	double tolerance = .25;
	double point = 1.0;
	
	int hasTopPrinted = 0;
	int hasBottomPrinted = 0;
	int hasLeftPrinted = 0;
	int hasRightPrinted = 0;
	int hasFrontPrinted = 0;
	int hasBackPrinted = 0;
	
	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );
		if(b2 == 1){
			break;
		}
		double x = mag(ax, ay, az);
		if (close_to (tolerance, point, x) == TRUE){
			if(az > .75){
				if (hasTopPrinted == 0) {
    				printf("top\n");
					hasTopPrinted = 1;
					hasBottomPrinted = 0;
					hasLeftPrinted = 0;
					hasRightPrinted = 0;
					hasFrontPrinted = 0;
					hasBackPrinted = 0;
				}
			}
			else if(az < -.75){
				if (hasBottomPrinted == 0){	
					printf("bottom\n");
					hasTopPrinted = 0;
					hasBottomPrinted = 1;
					hasLeftPrinted = 0;
					hasRightPrinted = 0;
					hasFrontPrinted = 0;
					hasBackPrinted = 0;
				}
			}
			else if(ax < -.75){
				if (hasLeftPrinted == 0){
					printf("left\n");
					hasTopPrinted = 0;
					hasBottomPrinted = 0;
					hasLeftPrinted = 1;
					hasRightPrinted = 0;
					hasFrontPrinted = 0;
					hasBackPrinted = 0;
				}
			}
			else if(ax > .75){
				if (hasRightPrinted == 0){
					printf("right\n");
					hasTopPrinted = 0;
					hasBottomPrinted = 0;
					hasLeftPrinted = 0;
					hasRightPrinted = 1;
					hasFrontPrinted = 0;
					hasBackPrinted = 0;
				}
			}
			else if(ay > .75){
				if (hasFrontPrinted == 0){
					printf("front\n");
					hasTopPrinted = 0;
					hasBottomPrinted = 0;
					hasLeftPrinted = 0;
					hasRightPrinted = 0;
					hasFrontPrinted = 1;
					hasBackPrinted = 0;
				}
			}
			else if(ay < -.75){
				if (hasBackPrinted == 0){
					printf("back\n");
					hasTopPrinted = 0;
					hasBottomPrinted = 0;
					hasLeftPrinted = 0;
					hasRightPrinted = 0;
					hasFrontPrinted = 0;
					hasBackPrinted = 1;
				}
			}	 
		}
	
	}	
    return 0;
}
double mag(double ax, double ay, double az){
		double r = sqrt(ax*ax+ay*ay+az*az);
    return r;
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
