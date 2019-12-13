#include "header.h"
extern sem_t blocks;
 
int create_block(void){                     //returns 1 if error has occured or 0 for success


    for (int i=TOTAL_RESOURCES; i>0 ; i--)
    {
        resource_table[i] = (void *)malloc(sizeof(struct block));

        if(NULL == resource_table[i]) 
        (*resource_table[i]).allocated_to = NULL ;         //nullifying thr pointer to structures manually

        {perror("Failed To Allocate Memory.\n");
        return 1;}
    }    

printf("Blocks Created\n");

return 0; 
}


void *get_block(pthread_t thread_id)            //takes the thread id and returns a void pointer to the structure
{
//static pthread_t *waiting_queue[TOTAL_THREADS];  // threads waiting in a queue for resource, worst case -> all are waiting

 if(sem_wait(&blocks))
        { perror("Error in sem_post.\n");
        }

for(int i=0 ; i < TOTAL_RESOURCES; i++) 
{
    if(NULL==(*resource_table[i]).allocated_to)
    {
        (*resource_table[i]).allocated_to = thread_id;
        
        return &((*resource_table[i]).array);       //returning the address of a block of 10 bytes
     }
}


}


int free_block(pthread_t thread_id)
{

for(int i=0 ; i < TOTAL_RESOURCES; i++) 
{
    if(thread_id == (*resource_table[i]).allocated_to )          //checking if the thread has occupied any blocks
    {
        (*resource_table[i]).allocated_to = NULL ;
        sem_post(&blocks);
                                           
        return 0;
     }
}

printf("Failed to free the block.\n");
return 1;

}



int destroy_blocks(void)
{
    for (int i=TOTAL_RESOURCES; i>0 ; i--)
    {
       free(resource_table[i]);

        if(NULL != resource_table[i]) {
        (*resource_table[i]).allocated_to = NULL ;         //nullifying thr pointer to structures manually

        perror("Failed To Deallocate Memory.\n");
        return 1;}
    }    

printf("Blocks Created\n");
}

