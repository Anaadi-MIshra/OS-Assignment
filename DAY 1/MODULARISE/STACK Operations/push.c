#include "stack.h"

void push(int x)
{
	if(top>=MAX-1){
		printf("stack is overflow\n");
		return;
	}
	else{
		buffer[++top] = x;
	}
}