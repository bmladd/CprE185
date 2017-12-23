

#include <stdio.h>
#include <math.h>


#define TRUE 1


double mag ( double x, double y, double z);

double timeFall(int t, int i); 

int close_to(double tolerance, double point, double value);




int main () {
	int t; 
	int i=0;
	double ax, ay, az;
	
	int stop = 0;
	int timeFinal, timeInt, timeUnd, percentDiff;
	double fallDist, prevVel, dropVel, airVel;
	
	
			printf("Ok, I'm now receiving data.\n");
			
			printf("I'm Waiting");
			
			scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
			
			
			//printf(" %d", i);
			
			
		while (TRUE) {
			
			scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
			
			
			for (i == 0; i<=4; ++i) {
				printf(".");
				
			}
			
			if(!close_to(0.2, mag(ax,ay,az), 1)) {
				printf("\nHelp me! I'm falling");
				timeInt = t;
				
			}
			
			//printf("echoing output: %d, %lf, %lf, %lf\n", t, az, ay, ax);
			
			while (!close_to(0.2, mag(ax,ay, az), 1)) {
				scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
				
				
				for (i == 5;i <=9; ++i) {
					printf("!");
				}
				//fflush(stdout);
			}
		
		if (close_to(0.2, mag(ax,ay,az),1)) {
			timeFinal = t;
			
			fallDist = (0.5*9.8)*(timeFall(timeFinal, timeInt) * timeFall(timeFinal, timeInt));
			
			
			
				fflush(stdout);
		}
		
		/*while (...) {
			prevVel = dropVel;
			
			dropVel = (prevVel + (9.8 * (1- mag(ax,ay,az))*timeFall(timeFinal, timeInt)));
			
			airVel = (dropVel * ((timeFinal-timeUnd)/1000.0));
			
			timeUnd = timeFinal;
		}
		} 
		
		if (close_to(0.25, mag(ax,ay,az), 1)) {
			printf("\nOuch! I fell %lf meters in %0.3lf seconds.\n", fallDist, timeFall(timeFinal, timeInt));
			
			printf("Compensating for air resistance, the fall was %lf meters.\n", airVel);
			
			percentDiff = (fabs(fallDist - airVel)/((fallDist+airVel)/2)*100); // modify to utilize the % sign.
			
			printf("This is %lf percent less than computed before.");
			
			
				fflush(stdout); */
		} 
		
		return 0;
}


double mag ( double x, double y, double z) {
		double magnitude;
		magnitude = sqrt((x*x)+(y*y)+(z*z));
		return magnitude;
	}
	
double timeFall(int t, int i) {
	double timeSec;
	
	timeSec = (t - i)/1000.0 ;
	
return timeSec;
}
	
int close_to(double tolerance, double point, double value){
	if (fabs(point - value) < tolerance){
		return 1;
	}
	else {
		return 0;
	}
	
}	



	
