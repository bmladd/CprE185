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
	int fun, avg_x, avg_y, avg_z;
	double min;
	double max;
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

	
	
	
	do {
		
		fun = read_acc(&a_x, &a_y, &a_z, &time, &b_Up, &b_Down, &b_Left, &b_Right);
		
		updatebuffer(x,lengthofavg, a_x);
		avg_x = avg(x,lengthofavg);
		maxmin(x, lengthofavg, &max, &min);
		
		
		
		
		
		
		
		
		fflush(stdout);
	}
	while(fun != 1);
	 
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
	printf("%d, %d", &min, &max);
	
	
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