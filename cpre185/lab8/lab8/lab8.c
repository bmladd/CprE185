#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);

int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);


int main(int argc, char* argv[]) {

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	double a_x, a_y, a_z; 
	int b_Up, b_Down, b_Left, b_Right, time;
	int fun = 0;
	int avg_x, avg_y, avg_z;
	double min_x, min_y, min_z;
	double max_x,max_y, max_z;
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

	
	
	
	while(fun != 1) {
		
		fun = read_acc(&a_x, &a_y, &a_z, &time, &b_Up, &b_Down, &b_Left, &b_Right);
		
		updatebuffer(x,lengthofavg, a_x);
		avg_x = avg(x,lengthofavg);
		maxmin(x, lengthofavg, &max_x, &min_x);
		printf("%lf, %d, %lf, %lf, ", a_x, avg_x, min_x, max_x);
		
		updatebuffer(y,lengthofavg,a_y);
		avg_y = avg(y,lengthofavg);
		maxmin(y,lengthofavg, &max_y, &min_y);
		printf("%lf, %d, %lf, %lf, ", a_y, avg_y, min_y, max_y);
		
		updatebuffer(z,lengthofavg,a_z);
		avg_z = avg(z,lengthofavg);
		maxmin(z,lengthofavg, &max_z, &min_z);
		printf("%lf, %d, %lf, %lf\n", a_z, avg_z, min_z, max_z);
		
		
		
		
		
		
		
		fflush(stdout);
	}
	
}


double avg(double buffer[], int num_items) {
	int i;
	double average; 
	double sum=0;
	
	for(i=0;i<num_items;i++) {
		sum = sum + buffer[i+1];
	}
	average = sum/num_items;
	
	return average;
}

void maxmin(double array[], int num_items, double* max, double* min) {
	int i;
	for(i=0;i<num_items;i++){
		if (array[i]>*max){
			*max = array[i];
		}
		if (array[i] < *min){
			*min = array[i];
		}
	}
	
}

void updatebuffer(double buffer[], int length, double new_item) {
	int i;
	for(i=0;i<(length-1);i++){
		buffer[i]=buffer[i+1];
	}
	buffer[i] = new_item;
}


int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	int ex1, ex2;
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", time, a_x, a_y, a_z, Button_UP, Button_DOWN, Button_LEFT, Button_RIGHT, &ex1, &ex2);
	
	if (*Button_LEFT == 1) {
		return 1;
	}
	
	else {
		return 0;
	}
	
}