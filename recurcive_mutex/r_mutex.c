#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

int count = 0;
pthread_mutex_t countMutex;
pthread_mutexattr_t attr;
                                                                                                

void *inc_thread (void* data)
{
    while (1)
    {
        pthread_mutex_lock (&countMutex);                  // using recursive mutex
        pthread_mutex_lock (&countMutex);
        pthread_mutex_lock (&countMutex);                  //thread lock 
        count++;
        printf("I am in inc thread and your inc is:%d\n", count);
        pthread_mutex_unlock (&countMutex);               //thread unlock 
        pthread_mutex_unlock (&countMutex);
        pthread_mutex_unlock (&countMutex);
    }
}

void *dec_thread (void* data)
{
    while (1)
    {
        pthread_mutex_lock (&countMutex);
        pthread_mutex_lock (&countMutex);
        pthread_mutex_lock (&countMutex);               //thread lock
        count--;
        printf("I am in dec thread and your inc is:%d\n", count);
        pthread_mutex_unlock (&countMutex);             //thread unlock 
        pthread_mutex_unlock (&countMutex);
        pthread_mutex_unlock (&countMutex);
    }
}

int main()
{
    pthread_t id_inc, id_dec;
    pthread_mutexattr_init(&attr);                                //init attribute and set type  
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
    pthread_mutex_init(&countMutex, &attr);                       //mutex init
    pthread_create (&id_inc, NULL, inc_thread, NULL);             //thread function name and argument want to send
    pthread_create (&id_dec, NULL, dec_thread, NULL); 
    pthread_join (id_inc,NULL);
    pthread_join (id_dec,NULL);                                   //join the main thread before it exit. 
    pthread_mutex_destroy(&countMutex);                           //mutex destroy
    return 0;
}