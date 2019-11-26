#include<stdio.h>
#include "libstack.a"

int main()
{
    int x;
    printf("PUSH\nPOP\nDISPLAY\n");
    scanf(" %d", &x);
switch(x)
{
    case 1:
    int temp;
    scanf(" %d",&temp);
    push(temp);
    break;
    case 2: 
    pop();
    break;



    default: break;
}

}