#include <stdio.h>
#include <math.h>


int main() {
	int i;
	int sum1 =0;
	int sum2 =0;
	int final =0;
	
	for(i=1; i <= 100; i++){
		sum1 = sum1 + (i*i);
	}
	
	for(i=1; i<=100; i++){
		sum2 = (sum2 + i);
	}
	sum2 = sum2 * sum2;
	final = sum2 - sum1;
	
	printf("%d", final);
	
	return 0;
}