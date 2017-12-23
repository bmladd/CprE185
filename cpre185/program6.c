// programing practice #5

/* 		Brandon Ladd

		bmladd@iastate.edu
		
		CPRE 185 Section X
		
		Reflection 1: For this practice I attempted to create new pointer values that would take existing variables and modify them in some way then return these modified values.
						along with this I attempted to clean up the multiplication table created in the last practice so that it read easier. 
					  
		Reflection 2: For the most part I was successful in what I set out to do, There are still a couple issues in getting the rows and columns to print how I want them to but its 
					a work in progress. along with this there were a few times that I couldn't figure out why my pointers were not calling correctly but in the end i realized i had 
					forgotten the astrick. 
					  
		Reflection 3: If I were to start this program over from scratch one thing that I would do to improve this or change in this is to play around with the different math operations
					  and see what kinds of crazy matheatical formulas that I could make the table do. along with this i would add more pointers, maybe a few into the array to see what 
					  that does to the output.
					  
		Reflection 4: The most significant thing that I have learned from this is that simple problems or goals are often some of the most complex to achieve, despite their easy going nature
					  even the simplest calculation can turn out to be a monster if you dont know what you are doing or you rush to get things done. As Always, before compiling, check the call for 
					each variable to see if it will print the right value and not just whatever random value it assigns to it. 
					  
					  
		
		Reflection 5 (Other comments): Still working through difficulties with trying to print the table output in an easy to read times table format. 
									   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAXX 25
#define MAXY 25

	int multTab [MAXX] [MAXY];
	
	int algebrafunct (int x, int y, int* newX, int* newY) {
		int equal;
		equal = (x*x) + (y*y);
		
		*newX = x*x;
		*newY = y*y;
		printf("When x is %d, and y is %d. The function is %d\n", x,y, equal);
		printf("%d, %d\n", *newX, *newY);
		
		return 0;
	}
	
	double circumference (double rad) {
		int i;
		double circNew;
		
		for(i=1; i < rad; ++i){
		circNew = (3.14 * rad) + i;
		}
		return circNew;
	}
	
	int timesTable(int multTab[MAXX] [MAXY], int* newMaxX, int* newMaxY) {
		int x, y;
		int argVal;
		for (y=0;y<MAXY;y++) { // for every column
			for(x=0;x<MAXX;x++) { // for every row
				argVal = x*y; // the value is x*y
				printf("%3d ", argVal); // prints the value of arg value for values x and y				
			if (y == MAXY && x == MAXX) {
				printf("\n");
			}
			}
		}
		*newMaxX = argVal*2;
		*newMaxY = argVal*3;
		printf("\n %d, %d", *newMaxX, *newMaxY);
		
		return 0;
	}
	
	
	int main (int newMaxX, int newMaxY, int newX, int newY) {
		int x, y;
		double rad;
		const int NUM_ELEMENTS = 4;
		int agelbraicNum[NUM_ELEMENTS];
		int i;
		float biggestNum =agelbraicNum[0];
		
		for (i=0; i < NUM_ELEMENTS; ++i) {
			scanf("%d %d", &x, &y);
			algebrafunct(x,y,&newX, &newY);
		}
		
		
		
		timesTable(multTab, &newMaxX, &newMaxY);
		
		return 0;
	}