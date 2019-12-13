#include <pthread.h> 
#include <stdlib.h>
#include <stdio.h>


void *FOO(void* count){
count++;
pthread_exit(&count);


}


int main(){
int count=0;
pthread_t var;
pthread_create(&var, NULL, FOO, &count);
sleep(2);
pthread_join(var, &count);
printf("count = %d\n", (int *)count);
return 0;
}

