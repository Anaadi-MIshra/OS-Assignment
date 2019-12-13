#include <semaphore.h>
#include<stdio.h>
#include <pthread.h>
sem_t  sem_in_proc;
sem_t  sem_proc_in;
int a,b;

void* input_thread(void* data)
{
    while(1)
    {
        sem_wait(&sem_in_proc);

        scanf("%d",&a);
        scanf("%d",&b);
        printf("a %d b %d\n",a,b);
        sem_post(&sem_proc_in);
    }
}
void* proc_thread(void* data)
{
    int sum=0;
    while(1)
    {
        sem_wait(&sem_proc_in);
        sum=a+b;
        printf("sum is %d",sum);
        sem_post(&sem_in_proc);
    }
}
int main(int argc, char const *argv[])
{
    pthread_t in_id,proc_id;
    sem_init(&sem_in_proc,0,1);
    sem_init(&sem_proc_in,0,0);
    pthread_create(&in_id,NULL,input_thread,NULL);
    pthread_create(&proc_id,NULL,proc_thread,NULL);
    pthread_join(in_id,NULL);
    pthread_join(proc_id,NULL);
    sem_destroy(&sem_in_proc);
   sem_destroy(&sem_proc_in);
    return 0;
}