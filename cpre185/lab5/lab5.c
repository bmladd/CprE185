/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

double mag ( double x, double y, double z); 

int close_to(double tolerance, double point, double value);



int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az;	
	int orient = 0;
	

	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	

	
		/*printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);

 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", t, mag(ax, ay, az)); 
		*/
		
		if ( close_to (0.1, mag(ax,ay,az),1) == 1) { // creates a loop that continues so long as the magnitude of acceleration is close to 1. 
			
				if (close_to(0.25, ax, 0) == 1 && close_to(0.25, ay, 0) ==1 && close_to(0.25, az, 1) && orient != 1) {
						printf("Top.\n");
						orient = 1;
						
				}	
				else if (close_to(0.25, ax, 0) == 1 && close_to(0.25, ay, 0) == 1 && close_to(0.25, az, -1) == 1 && orient != 2) {
						
						printf("Bottom.\n");
						orient = 2;
						
				}
				
				else if(close_to(0.25, ax, -1) == 1 && close_to(0.25, ay, 0) == 1 && close_to(0.25, az, 0) == 1 && orient != 3) {
					
					printf("left.\n");
					 orient = 3;
				} 
				
				else if (close_to(0.25, ax, 1) == 1 && close_to(0.25, ay, 0) == 1 && close_to(0.25, az, 0) == 1 && orient != 4 ) {
					
					printf("right.\n");
					orient = 4;
				
				}
				
				else if (close_to(0.25, ay, 1) == 1 && close_to(0.25, ax, 0) == 1 && close_to(0.25, az, 0) == 1 && orient != 5) {
					
					printf("front.\n");
					orient = 5;
					
				}
				else if (close_to(0.25, ay, -1) == 1 && close_to(0.25, ax, 0) == 1 && close_to(0.25, az, 0) == 1 && orient != 6) {
					
					printf("Back.\n");
					orient = 6;
					
				}
				
			}	
		 
		 if (b1 == 1) {
						break;
				
				
				
				
		}
		
		
	
    
	}
	
	
}


double mag ( double x, double y, double z) {
		double magnitude;
		magnitude = sqrt((x*x)+(y*y)+(z*z));
		return magnitude;

}




int close_to(double tolerance, double point, double value){
	if (fabs(point - value) < tolerance){
		return 1;
	}
	else {
		return 0;
	}

}	
			
			
		


	
	
	
