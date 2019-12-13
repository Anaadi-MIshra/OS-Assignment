#include <pthread.h>
#include <stdio.h>
int count=0;
void *inc();
void *dec();

int main()
{
    pthread_t incId,decId;
    pthread_create(&incId,NULL,inc,NULL);
    pthread_create(&decId,NULL,dec,NULL);

    pthread_join(incId,NULL);
    pthread_join(decId,NULL);
    return 0;
}
void *inc()
{
    while(1)
    {
        count++;
        printf("inc %d",count);
    }
}

void* dec()
{
    while(1)
    {
        count--;
        printf("inc %d",count);
    }
}
