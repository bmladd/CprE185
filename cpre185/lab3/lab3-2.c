#include <stdio.h>

int main() {
	
	int integerAns1, integerAns2, integerAns3, integerAns4, integerAns5;
	double deciAns1, deciAns2, deciAns3, deciAns4, deciAns5, deciAns6;
	double areaOfCircle, conversionFt2M, convertF2C; 
	double pi = 3.14;
	
	integerAns1 = 6427 + 1725;
	printf("6427 + 1725 = %d\n", integerAns1);
	
	integerAns2 = (6971 * 3925) - 95;
	printf("(6971 * 3925) - 95 = %d\n", integerAns2);
	
	integerAns3 = (22/3) *3;
	printf("(22/3) * 3 = %d\n", integerAns3);
		
	integerAns4 = 22/(3*3);
	printf("22/(3*3) = %d\n", integerAns4);
	
	integerAns5 = 22.0/3 * 3.0; 
	printf("22.0/3 * 3.0 = %d\n", integerAns5);
	
	deciAns1 = 79 + 12/5;
	printf("79 + 12/5 = %.2lf\n", deciAns1);
	
	deciAns2= 3640/107.9;
	printf("3640/107.9 = %.2lf\n", deciAns2);
	
	deciAns3 = 22/(3*3);
	printf("22/(3*3) = %.2lf\n", deciAns3);
	
	deciAns4 = 22/3*3;
	printf("22/3*3 = %.2lf\n", deciAns4);
	
	deciAns5 = (22.0/3)*3.0;
	printf("(22.0/3) * 3.0 = %.2lf\n", deciAns5);
	
	deciAns6 = 22.0/3.0 *3.0;
	printf("22.0/3.0 * 3.0 = %.2lf\n", deciAns6);
	
	areaOfCircle = (23.567/(2 * pi)) * (23.567/(2*pi)) * pi;
	printf("Area of the cirlce = %.2lf\n", areaOfCircle);  // compute the area of a cirlce
	
	conversionFt2M = 14 * 0.3048;
	printf("14ft = %.2lf m\n", conversionFt2M); // convert Feet to Meters
	
	convertF2C = (76 -32)/1.8;
	printf("%.2lf = (76-32)/1.8\n", convertF2C); // convert degress Fahrenheit to degress Centigrade
	
	
	
}