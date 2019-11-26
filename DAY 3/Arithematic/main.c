#include<stdio.h>
#include<stdlib.h>
#include "arith.h"

int main(int argc, char* argv[])
{
    int a=atoi(argv[1]); //*(argv[1]) -48;
    int b= atoi(argv[2]);//*(argv[2]) -48;
    printf("%d\n",a);
        printf("%d\n", b);
    printf("Addition is %d\n", add(a,b));
    printf("Difference is %d\n", diff(a,b));
    printf("Multiplication is %d", mul(a,b));


   return 0; 
}