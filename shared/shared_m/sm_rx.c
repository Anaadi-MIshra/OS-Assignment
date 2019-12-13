#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>

int *count;
int *a;

sem_t *s1;
sem_t s2;

int main()
{
    int md,sum;
    md=shm_open("/desd11",O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(md,3*sizeof(int));
    s1=sem_open("/sema",O_CREAT | O_RDWR, S_IRUSR | S_IWUSR,0);

    s2=*s1;

    count=(int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,md,0);
    a=count;

    printf("1st Shared Memory no. is %d\n",*(count+0));
    printf("2nd Shared Memory no. is %d\n",*(count+1));

    sum=(*(a+0))+(*(a+1));
    (*(a+2))=sum;

    printf("Sum at Rx is: %d\n",*(a+2));
    sem_post(s1);

    sem_close(&s2);
    return 0;
}