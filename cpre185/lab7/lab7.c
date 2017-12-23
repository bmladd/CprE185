// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
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
	
	
// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2

double roll(double x_mag){
	double role;
	if (x_mag > 1.0){
		x_mag = 1.0;
	}
	else if (x_mag< -1.0){
		x_mag = -1.0;
	}
	else {
		x_mag = x_mag;
	}
		role = asin(x_mag);
	return role;
}
// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2

double pitch(double y_mag){
	double pike;
	if (y_mag> 1.0) {
		y_mag = 1.0;
	}
	
	else if (y_mag< -1.0) {
		y_mag = -1.0;
	}
	
	else {
		y_mag = y_mag;
	}
	
		pike = asin(y_mag);
	
	return pike;
	}
	

// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad) {
		int x;
		x = rad * (80/PI); 	
	return x;
}
// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times

void print_chars(int num, char use) {
	int i;
	
	for(i=0; i < fabs(num); ++i) { printf("%c", use);}
		
}
//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.

void graph_line(int number) {
	int i;
		if (number>0) {
			print_chars((40-number), ' ');
			print_chars(number, 'l');
			printf("0");
					
		}
		
		
		if (number == 0) {
			print_chars(40, ' ');
			printf("0");
		}
		
		if (number < 0) {
			print_chars(40, ' ');
			printf("0");
			print_chars(number,'r');	
		}
		printf("\n");
}


int main(){
	double x, y, z, A;			// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right, n, fun ,time;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	
	n =1;//insert any beginning needed code here

	do
	{
		fun = read_acc(&x, &y, &z, &time, &b_Up, &b_Down, &b_Left, &b_Right); // Get line of input
		
		if (b_Down == 1) {
			n = 1;
		}
		
		if(b_Up==1) {
			n=2;
		}
		
		roll_rad = roll(x);
		
		pitch_rad = pitch(y); // calculate roll and pitch
		
		// printf("%lf, %lf", roll_rad, pitch_rad);
		if (1 == b_Down || n==1) {  // switch between roll and pitch(up vs. down button) & caluclate roll/pitch
			A = roll_rad;
		n =1;
		}// measure roll
		
		else if (1 == b_Up || n ==2) {
			A = pitch_rad;
		n =2; //measure pitch
		}
		
		//printf("%d\n", A);
		//if (scaled_value){
		
		graph_line(scaleRadsForScreen(A));  // Output your graph line
		

		fflush(stdout);
		}
	 while (fun != 1); 
		 
	
		// Modify to stop when left button is pressed	     
	return 0;
}
