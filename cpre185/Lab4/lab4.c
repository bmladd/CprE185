/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */

double mag ( double x, double y, double z);
 
int millis(int t);

int seconds(int t);

int minutes(int t);


int main(void) {
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

 /* CODE SECTION 0 */
		printf("Echoing output: %lf, %lf, %lf, %lf\n",(1.0* t/1000), ax, ay, az);

 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az)); 
				
 	
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 
	
	
	

return 0;
}
}

double mag ( double x, double y, double z) {
		double magnitude;
		magnitude = sqrt((x*x)+(y*y)+(z*z));
		return magnitude;
	}/* Put your functions here */

int minutes(int t) {
	int minutes;
	minutes = (t/1000) * (1.0/60.0);
	return minutes;
}

int seconds(int t) {
	int seconds;
	seconds = ((t/1000) % 60);
	return seconds;
}

int millis(int t) {
	int millis;
	if (t < 1000) {
		millis = t;
	}
	else {
		millis =((t-(t/1000)) % 1000);
	}
	return millis;
}


