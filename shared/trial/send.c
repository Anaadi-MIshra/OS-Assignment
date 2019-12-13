#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

    sem_t *semaphore = sem_open("/MEDIUM", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, 0);

    if(semaphore == NULL)
    {
        perror("Failed to open semaphore from sender.\n");
        exit(1);
    }

    for(int i=0; i<10; i++)
    {
        
        if(sem_wait(semaphore) < 0){
            perror("SEM_WAIT failed from sender\n");
            
        }
        //sleep(20);

            printf("printing from sender. : %d\n", i);

        if(sem_post(semaphore) < 0){
            perror("Failed to POST semaphore from sender.\n");
        }    
        
        sleep(1);


    }


        if(sem_close(semaphore) < 0){
            perror("Failed to close semaphore from sender.\n");
            exit(1);
        }

    return 0;
}




