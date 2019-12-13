#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t sem_in_proc;
sem_t sem_proc_in;
 //pthread_t incid,decid;
int a,b;

void *input_thread(int* data)
{
while (1)
{
    sem_wait(&sem_proc_in);
    scanf("%d",&a);
    scanf("%d",&b);
    printf("Input:a:%d  b:%d\n",a,b);
    sem_post(&sem_in_proc);
}

}

void *output_thread(int* data)
{
int sum;
while (1)
{
    sem_wait(&sem_in_proc);
    sum=a+b;
    printf("output:sum:%d\n",a+b);
    sem_post(&sem_proc_in);
}

}

int main(int argc, char const *argv[])
{
    pthread_t incid,decid;
    sem_init(&sem_in_proc,0,0);
    sem_init(&sem_proc_in,0,1);
    pthread_create(&incid,NULL,input_thread,NULL);
    pthread_create(&decid,NULL,output_thread,NULL);
    pthread_join(&incid,NULL);
    pthread_join(&decid,NULL);
    sem_destroy(&sem_in_proc);
    sem_destroy(&sem_proc_in);
    return 0;
}


