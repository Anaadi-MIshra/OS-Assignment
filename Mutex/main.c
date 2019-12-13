#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 


int count = 0;
pthread_mutex_t countMutex;
void *inc_thread (void* data)
{
    while (1)
    {
        pthread_mutex_lock (&countMutex);                  //thread lock 
        count++;
        printf("I am in inc thread and your inc is:%d\n", count);
        pthread_mutex_unlock (&countMutex);               //thread unlock 
    }
}

void *dec_thread (void* data)
{
    while (1)
    {
        pthread_mutex_lock (&countMutex);               //thread lock 
        count--;
        printf("I am in dec thread and your inc is:%d\n", count);
        pthread_mutex_unlock (&countMutex);             //thread unlock 
    }
}

int main()
{
    pthread_t id_inc, id_dec;
    pthread_mutex_init(&countMutex, NULL);                  //mutex init
    pthread_create (&id_inc, NULL, inc_thread, NULL);       //thread function name and argument want to send
    pthread_create (&id_dec, NULL, dec_thread, NULL); 
    pthread_join (id_inc,NULL);
    pthread_join (id_dec,NULL);                             //join the main thread before it exit. 
    pthread_mutex_destroy(&countMutex);                     //mutex destroy
    return 0;
}
