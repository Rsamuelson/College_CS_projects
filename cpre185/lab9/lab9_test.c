#include <stdio.h>
#include <math.h>
#include <unistd.h>

double calc_roll(double x_mag){
	int x_tilt;
	if(x_mag > 1){
		x_mag = 1;
	}
	else if (x_mag < -1){
		x_mag = -1;
	}
	double x_rad_value = 1 / asin(x_mag);
	printf("%lf\n", x_rad_value);
	if(x_rad_value > .45){
		x_tilt = 1;
	}
	else if(x_rad_value < -.45){
		x_tilt = -1;
	}
	else{
		x_tilt = 0;
	}
	
	return x_tilt;
}

int main(){
	double x = 0;
	double y;
	printf("print a number: ");
	scanf("%lf", &x);
	printf("%lf\n", x);
	y = calc_roll(x);
	printf("%lf", y);
	return 0;
}
