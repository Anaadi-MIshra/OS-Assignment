
#include "stack.h"

 top = -1;

int main()
{
	int ch,num;
	while(1){
		printf("\n Enter\n 1.PUSH into stack\n 2.POPED from stack\n 3.Find TOP of stack\n 4.Display\n");
		scanf("%d",&ch);

		switch(ch){
		case 1:
			printf("Enter the value you want to\n ");
			scanf("%d",&num);
			push(num);
			break;
		case 2:
			pop();
			break;
		case 3:
			printf("Top of stack is:%d\n",top);
			break;
		case 4:
			display();
			break;
		default:
			break;
		}
	}
	return 0;
}
