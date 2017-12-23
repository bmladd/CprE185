/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
int NumButtons(int a, int b, int x, int y, int s, int t);



int main(void) {
	int a,b,x,y,s,t;
	double  ax, ay, az; 	


	while (TRUE) {
		
		scanf("%d, %d, %d, %d, %d, %d\n", &a, &b, &x, &y, &s, &t);
	
		printf("Number of buttons pressed: %d\r\n", NumButtons(a,b,x,y,s,t));
	
		fflush(stdout);
	
	
	}
	return 0;
	
}

int NumButtons(int a, int b, int x, int y, int s, int t) {
	int Buttons;
	
	Buttons = a + b + x + y + s + t;
	
	return Buttons;
}


