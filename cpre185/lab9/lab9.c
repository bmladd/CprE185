// WII-MAZE Skeleton code written by Jason Erbskorn 2007
// Edited for ncurses 2008 Tom Daniels
//Updated for Esplora 2013 TeamRursch185



#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>

#define PI 3.14159

// Screen geometry
// Use ROWS and COLUMNS for the screen height and width (set by system)
// MAXIMUMS
#define COLUMNS 100
#define ROWS 80

#define MAXTIME 100000

#define AVATAR 'L'
#define WALL '*'
#define EMPTY_SPACE ' '
 


// 2D character array which the maze is mapped into
char MAZE[COLUMNS][ROWS];

void draw_character(int x, int y, char use) // DO NOT TOUCH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	mvaddch(y,x,use);    
	refresh();
}

void generate_maze(int difficulty){
	int i, j;
		for(i=0; i<ROWS;i++){
			for(j=0;j<COLUMNS;j++){
				if(rand() %100 >= (difficulty)){
				MAZE[j][i] = EMPTY_SPACE;
				}
				else{
					MAZE[j][i] = WALL;
				}
			}
		}
		
}
// PRE: MAZE[][] has been initialized by generate_maze()
// POST: Draws the maze to the screen 
void draw_maze(void){
		int i, j;
		
		MAZE[49][0] = AVATAR; 
		draw_character(49,0,MAZE[49][0]);
		for (i=0;i<ROWS; i++){
			for(j=0;j<COLUMNS;j++){
				draw_character(j,i,MAZE[j][i]);
			}
		}
	
		
		
}

	
  
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
	
// Main - Run with './explore.exe -t -a -b' piped into STDIN
void main(int argc, char* argv[]){
	int time, timeT, b_Up, b_Down, b_Left, b_Right, ex1, ex2;
	double a_x, a_y, a_z;
	int avg_x, avg_y, avg_z;
	int lengthofavg = 0;
	int fun = 0;
	double x[100], y[100] ,z[100];
	int i;
	int a=49;
	int b=0;
	// setup screen    
	initscr();
	refresh();

	if(argc>1){
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		
	}
	if (lengthofavg <1 || lengthofavg >100) {
		printf("Invalid length\n");
		
	}
	
	
	generate_maze(lengthofavg);
	draw_maze();// Generate and draw the maze, with initial avatar

	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &a_x, &a_y, &a_z, &b_Up, &b_Down, &b_Left, &b_Right, &ex1, &ex2);// Read accelerometer data to get ready for using moving averages.    
	timeT = time;
	
	// Event loop
	do
	{

		MAZE[a][b]= AVATAR;
		
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &a_x, &a_y, &a_z, &b_Up, &b_Down, &b_Left, &b_Right, &ex1, &ex2);
	   //for(i=0;i<MAXTIME;i++){}
	   fun = read_acc(&a_x, &a_y, &a_z, &time, &b_Up, &b_Down, &b_Left, &b_Right);
		   if((time - timeT >= 500)){
			   if((MAZE[a+1][b] != WALL) && (a < COLUMNS) && (a_x< -0.1)){
				   draw_character(a+1,b, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   a++;
			   }
			   else if((MAZE[a-1][b] != WALL) && (a > 0) && (a_x> 0.1)){
				   draw_character(a-1,b, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   a--;
			   }
			    if(MAZE[a][b+1] != WALL){
				   draw_character(a,b+1, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   b++;
			   }
			   if ((MAZE[a+1][b] == WALL) && (MAZE[a-1][b] == WALL) && (MAZE[a][b+1] == WALL)) {
				break;
	}
		timeT = time;
	   fflush(stdout);
		}
			   // Read data, update average
		
	}	// Is it time to move?  if so, then move avatar

	 while(fun !=1 && b != ROWS-1);
	{
		fun = read_acc(&a_x, &a_y, &a_z, &time, &b_Up, &b_Down, &b_Left, &b_Right);
		
		updatebuffer(x,lengthofavg, a_x);
		avg_x = avg(x,lengthofavg);
		
		updatebuffer(y,lengthofavg,a_y);
		avg_y = avg(y,lengthofavg);
		
		updatebuffer(z,lengthofavg,a_z);
		avg_z = avg(z,lengthofavg);
		
		
		fflush(stdout);
		
		
	} // Change this to end game at right time 

	// Print the win message
	endwin();
	
	if(b_Left==1 || fun ==1){
		printf("Host Ended Game...");
	}
	else if (b==ROWS-1){ printf("YOU WIN!\n");}

	else printf("GAME OVER...");
}


// PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
// POST: Draws character use to the screen and position x,y
//THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
//YOU DO NOT NEED TO CHANGE THIS FUNCTION.



