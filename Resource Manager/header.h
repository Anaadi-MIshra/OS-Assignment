#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#define TOTAL_RESOURCES 3
#define TOTAL_THREADS 5

extern sem_t blocks;

extern struct block{               //structure for individual blocks and thread_ids to which it is allocated 
    int array[10];
    pthread_t allocated_to;
};

static struct block* resource_table[TOTAL_RESOURCES];        //resource_table is used to store the addresses of the created blocks 


int create_block(void);
void *get_block(pthread_t);
int free_block(pthread_t thread_id);
int destroy_blocks(void);
