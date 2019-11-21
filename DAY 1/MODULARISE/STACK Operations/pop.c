#include "stack.h"


void pop()
{
	
	if(top == -1){
		printf("Stack is underflow\n");
		return;
	}
	else{
		 buffer[top--];
	}

}
