#include <stdio.h>

#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items){
	double total = 0;
	double averageOfTotal;
	int i;
	for(i = 0; i < num_items; i++){
		total = buffer[i] + total;
		
	}
	averageOfTotal = total / num_items;
	return averageOfTotal;
}

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min){
	int i;
	for(i = 0; i < num_items; i++){
		if (i == 0) {
			*max = array[i];
			*min = array[i];
		}
		if(array[i] > *max){
			*max = array[i];
		}
		else if(array[i] < *min){
			*min = array[i];
		}
	}
}

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item){
	int i;
	int j = 0;

	for(i = 0; i < length; i++){
		buffer[i] = buffer[i + 1];
		j++;
	}

	buffer[j] = new_item;
}




int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	/* PUT YOUR CODE HERE */
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az;
	double xmax, xmin, ymax, ymin, zmax, zmin;
	int i;
	for(i = 0; i < lengthofavg; i++){
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );
		if (b4 == 1) {
			return 0;
		}
		x[i] = ax;
		y[i] = ay;
		z[i] = az;
	}

    while (b4 == 0) {
		//  do some stuff here
		maxmin(x, lengthofavg, &xmax, &xmin);
		maxmin(y, lengthofavg, &ymax, &ymin);
		maxmin(z, lengthofavg, &zmax, &zmin);
		printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n", ax, ay, az, avg(x, lengthofavg), avg(y, lengthofavg), avg(z, lengthofavg), xmax, xmin, ymax, ymin, zmax, zmin);
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );
		updatebuffer(x, lengthofavg, ax);
		updatebuffer(y, lengthofavg, ay);
		updatebuffer(z, lengthofavg, az);
		}		
}