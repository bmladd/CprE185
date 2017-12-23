// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses/ncurses.h>

#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 1   // set to 0 to disable debug output


#define AVATAR '|'
#define EMPTY_SPACE ' '

#define COLUMNS 80
#define ROWS 6
// reads words from the file
// into wl and trims the whitespace off of the end
int readWords(char* wl[MAXWORDS], char* filename); 

//modifies s to trim white space off the right side
void trimws(char* s) ;

void draw_character(int x, int y, char use);

int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

int WordPlace(int x, int y);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int time, timeT, b_Up, b_Down, b_Left, b_Right, ex1;
	int b_Joy, Joy_R, Joy_L, Joy_U, Joy_D, ex2, ex3;
	double x[100], y[100] ,z[100];
	char sent[80] = "\0";
	int len[80];
	int wordCount;
	int i, n ,w;
	int space = 0;
	int a= 11;
	int b=0;
	int dir = 0;
	wordCount = readWords(wordlist, argv[1]);

	int fun = 0;
	
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &b_Down, &b_Up, &b_Left, &b_Right, 
	&b_Joy, &ex1, &Joy_D, &Joy_U, &Joy_L, &Joy_R, &ex2, &ex3);
	
	timeT = time;
	
	initscr();
	refresh();
	
	draw_character(a,b, AVATAR);
	
	
	
		for (i = 0; i< wordCount; i++) {
			mvprintw(i/5+space, i%5*15,"%s", wordlist[i]);
				
			}
			refresh();
			
	do {
			scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &b_Down, &b_Up, &b_Left, &b_Right, 
	&b_Joy, &ex1, &Joy_D, &Joy_U, &Joy_L, &Joy_R, &ex2, &ex3);
	
		if((time - timeT >= 200)){
			   if(Joy_R==1 && (a+15 < 74) && (ex2 < -400) && dir != 1) {
				   draw_character(a+15,b, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   a+=15;
				   dir =1;
			   }
			   if(Joy_L==1 && (a-15 > 10) && (ex2 > 400) && dir != -1){
				   draw_character(a-15,b, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   a-=15;
				   dir = -1;
			   }
			    if(Joy_D==1 && (b +1 < wordCount/5) && (ex3 > 400) && dir != 2){
				   draw_character(a,b+1, AVATAR);
				   draw_character(a,b,EMPTY_SPACE);
				   b++;
				   dir = 2;
			   }
			   if (Joy_U==1 && (b-1 > 0) && (ex3 < -400) && dir != -2) {
				draw_character(a,b-1, AVATAR);
				draw_character(a,b,EMPTY_SPACE);
				b--;
				dir =-2;
				}
			timeT = time;
			dir =0;
			
			fflush(stdout);
		
		
			if (b_Up==1){
			strcat(sent, " ");
			strcat(sent, wordlist[WordPlace(a,b)]);
			mvprintw(wordCount/5+2,0, "%s", sent);
			len[i] += strlen(sent);
			refresh();
		}
		if(b_Right==1){
			
		}
		if(b_Left==1){
			strcat(sent, wordlist[WordPlace(a,b)]);
			mvprintw(wordCount/5+2,0, "%s", sent);
			len[i] += strlen(sent);
			refresh();
		}
		
		if(b_Down==1){
			n = strlen(sent);
			w = strlen(wordlist[WordPlace(a,b)]);
			for(i=0; i< w; i++){
				sent[i+(n-w)] = ' ';
				mvprintw(wordCount/5+2,n-w+i, " %c", sent[n-w+i]);
			}
			refresh();
			
			sent[n-w] = NULL;
			mvprintw(wordCount/5+2,0, "%s", sent);
			refresh();
		}
		}
		
	}
	
	while(fun != 1);
// most of your code goes here.  
{
	
	

		
		
		
		/*if (b_Joy==1){
			mvprintw(,0, "%s", wordlist[WordPlace(a,b)]);
		}
		if(b_Right==1){
			
		}
		if(b_Left==1){
			printf("");
		}
		if(b_Up==1){
			printf(" ");
		}
		if(b_Down==1){
			draw_character(a,b, EMPTY_SPACE);
		} 
		refresh();*/
		
}
	 
	endwin();
	
    return 0;
	
}


void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
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

int WordPlace(int x, int y){
	int i;
	i = y*5 +x/15;
	return i;
}
int readWords(char* wl[MAXWORDS], char* filename) {
	int numread =0;
	char line[WORDLEN];
	char *p;
	FILE* fp = fopen(filename,"r");
	if(fp == NULL)
	{
		perror("fopen()");
		return 0;
	}
	while (!feof(fp)) {
		p  =fgets(line, WORDLEN, fp);
		if (!feof(fp) && p !=NULL) {
			trimws(line);
			wl[numread] = (char *)  malloc(strlen(line)+1);
			strcpy(wl[numread], line);
			numread++;
			}
		} 
	fclose(fp);
	return numread;	
	}
void draw_character(int x, int y, char use) // DO NOT TOUCH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	mvaddch(y,x,use);    
	refresh();
}



