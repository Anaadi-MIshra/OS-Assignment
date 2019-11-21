#include "stack.h"

void display()
{
	if(top == -1 ){
		printf("Stack is empty\n");
	}
	else{
		for(int i = top; i >=0; i--){
			printf("%d\n",buffer[i]);
		}
	}
}