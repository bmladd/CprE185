

#include <stdio.h> //LAB2-0.c 

int main(int argc, char* argv[]) {
     int x, y, z;
    printf("Enter a width:"); 
    scanf("%d", &x);
    printf("Enter a height:");
    scanf("%d", &y);
    printf("A %d by %d rectangle's area is %d\n", x, y, x*y);
    printf("Enter a length:");
    scanf("%d", &z);
    printf("A %d by %d by %d prism's volume is %d\n", x, y, z, (x*y*z)); 
    
    


    return 0;
}

