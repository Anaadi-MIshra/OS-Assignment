#include <stdio.h>
#include <pthread.h>

int event = 0;
pthread_mutex_t eventMutex = PTHREAD_MUTEX_INITIALIZER;    //static initialization of mutex
pthread_cond_t Condvar;                                //conditional variable 

void *wait_thread(void *arg)
{
    printf("WT Grab mutex\n");
    pthread_mutex_lock(&eventMutex);
    while (event != 1)                                     //condition
    {
        printf("WT Conditionally waiting\n");
        pthread_cond_wait(&Condvar, &eventMutex);          //giveing mutex to other thread conditionally
        printf("WT Out of Conditionally waiting\n");
    }
    printf("WT Event true\n");
    pthread_mutex_unlock(&eventMutex);
    printf("WT Releasing mutex\n");
}

void *signal_thread(void *arg)
{
    printf("ST Grab mutex\n");
    pthread_mutex_lock(&eventMutex);
    event = 1;
    printf("ST Event made true\n");
    pthread_mutex_unlock(&eventMutex);
    printf("ST Releasing mutex\n");
    pthread_cond_signal(&Condvar);                      //signal to conditional wait thread.
}

int main()
{
    pthread_t wait_id, signal_id;
    pthread_cond_init(&Condvar, NULL);
    pthread_create(&wait_id, NULL, wait_thread, NULL);
    pthread_create(&signal_id, NULL, signal_thread, NULL);
    pthread_join(wait_id, NULL);
    pthread_join(signal_id, NULL);
    pthread_cond_destroy(&Condvar);
    return 0;
}
