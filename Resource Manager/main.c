#include "header.h"

void *thread_task(void *data)
{
    int temp = *((int*)data);
    char *p;
    printf("RTC Thread: %d. \n", temp);
    p = get_block(pthread_self());
    printf("Block Acquired.\n");
    sleep(2);
    if(1 == free_block(pthread_self()))
    {printf("Error\n");
    }
}


int main(){

int t1 = 0;
int t2 = TOTAL_RESOURCES;
int sem_init( blocks, t1 , t2);
int thread_count=0;
pthread_t id_thread[TOTAL_THREADS];

create_block();
    printf("Before Thread: \n");
    for(int i = 1; i<= TOTAL_THREADS ; i++){
    pthread_create(&id_thread[i-1], NULL, thread_task, thread_count++);
    }


for(int i = 1; i<= TOTAL_THREADS ; i++){
    pthread_join(id_thread[i-1], NULL);
    }

    printf("After Thread: \n");
    destroy_blocks();
    return 0;
}