// programing practice #5

/* 		Brandon Ladd

		bmladd@iastate.edu
		
		CPRE 185 Section X
		
	Goals: The purpose of this program was to explore string functions and to see if  the program written would be able to locate 
			the file run with it and return the correct values and string characters after it was done.
	Accomplishments: For the most part this program practice was successful, however there are still issues with the string biggestWord 
					and the fact that I know in the file that I ran with it there is a longer word that the word long. 
	Changes: If I were to do this program over I would add more string functions such as strcmp and introduce in some text functions to 
			replace certain words with others when they were found. On top of this I would attempt to make the program write an entire 
			paragraph just from one sentence of input. (because why not.)
	What I learned: By experimenting with this I learned that I can use a code to proof read my creative writing for english and maybe 
					even print an entire essay for me in less time that if I were to write the essay myself. I also learned that string 
					functions can be devilishly tricky if you don't know exactly what the function is and what it does to your arrays and strings. 
	Comments: N/A for this one.  
									   
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define NUMWORDS 26000
#define LONGEST 45

	
	//int words(int wordList[NUMWORDS][LONGEST], int numwords, )
	
	
	//still need to utilize and strcat.
	
	int main () {
		
		int i, length;
		char biggestWord [LONGEST], words[LONGEST];
		char wordList[NUMWORDS][LONGEST];
		
		while (scanf(" %45s", biggestWord) == 1) {
			strcpy(&(wordList[i][0]) , biggestWord);
			i++;
		}
		strcat(words,biggestWord);
		length = strlen(biggestWord);
		
		printf("\n Read %d words\n", i);
		printf(" %s\n", biggestWord);
		printf(" '%s' is the biggest word with %d characaters.\n", biggestWord, length);
		printf("%s\n", words);
		
		return 0;
	}