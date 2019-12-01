#include <stdio.h> 
#include <stdlib.h> 

#include <pthread.h> 

int i=0;

void *myThreadFun(void *vargp) 
{ while(1)
	printf("2nd thread %d\n", i--);
	//return NULL; 
} 

int main() 
{ 
	pthread_t thread_id; 
	printf("Before Thread\n"); 
	pthread_create(&thread_id, NULL, myThreadFun, NULL); 
	//pthread_join(thread_id, NULL); 
	//printf("After Thread\n"); 
	while(1)
	printf("main thread %d\n", i++);
    exit(0); 
}
