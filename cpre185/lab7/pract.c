#include <stdio.h>
#include <math.h>




int isValidISBN(int arr[10]) {
	int total;
	
	total = ((arr[0]*10)+(arr[1]*9)+(arr[2]*8)+(arr[3]*7)+(arr[4]*6)+(arr[5]*5)+(arr[6]*4)+(arr[7]*3)+(arr[8]*2)+(arr[9]*1));
		
		total = total % 11;
		
		if(total > 0) {
			printf("%d%d%d%d%d%d%d%d%d%d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
			return 0;
		}
		else {
			return 1;
		}
		
}




void scanISBN( int arr[10]) {
	char temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10;
	scanf(" %c%c%c%c%c%c%c%c%c%c", &temp1, &temp2, &temp3, &temp4, &temp5, &temp6, &temp7, &temp8, &temp9, &temp10);
	
	arr[0] = temp1 - '0';
	arr[1] = temp2 - '0';
	arr[2] = temp3 - '0';
	arr[3] = temp4 - '0';
	arr[4] = temp5 - '0';
	arr[5] = temp6 - '0';
	arr[6] = temp7 - '0';
	arr[7] = temp8 - '0';
	arr[8] = temp9 - '0';
	arr[9] = temp10 - '0';
	
	
	
}


int main(void) {
	int Num_Elements, i;
	int arr[10];
	
	scanf("%d", &Num_Elements);
	
	for (i = 0; i < Num_Elements; i++) {
		scanISBN(arr);
		
		isValidISBN(arr);
		
			
	}
	
	return 0;
}