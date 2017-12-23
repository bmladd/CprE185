#include <stdio.h>
#include <math.h>

#define NUMLEN 50

int main() {
	FILE *NumersTXT;
	int sum =0;
	int numArr[100][50];
	int final[100];
	int i;
	int j;
	int k = 99;
	
	NumersTXT = fopen("Numbers.txt", "r");
	
	

		for(i=0;i<100;i++){
			for(j=0;j<50;j++){
				fscanf(NumersTXT, "%1d", &numArr[i][j]);
			}
		}
		
		for(j=49;j>=0;j--){
			for(i=0;i<100;i++){
				sum = sum + numArr[i][j];
			}
			final[k] = sum % 10;
			k--;
			sum = sum /10;
					}
		
	
	

	final[k] = sum;
	sum = 0;
	
	printf("%d", numArr[3][48]);
	
	for(i=0; i<100; i++){
		printf("%d", final[i]);
	} 
return 0;
}
