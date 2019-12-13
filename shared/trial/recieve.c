#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    sem_t *semaphore = sem_open("/MEDIUM", O_RDWR);

    if(semaphore == NULL)
    {
        perror("Failed to open semaphore from reciever.\n");
        exit(1);
    }

    for(int i=0; i<10; i++)
    {
        
        if(sem_post(semaphore) < 0){
            perror("SEM_WAIT failed from reciever\n");
            
        }

            printf("printing from reciever. : %d\n", i);

        if(sem_wait(semaphore) < 0){
            perror("Failed to POST semaphore from reciever.\n");
        }    
        
        sleep(3);


    }


        if(sem_close(semaphore) < 0){
            perror("Failed to close semaphore from reciever.\n");
            exit(1);
        }

    return 0;
}