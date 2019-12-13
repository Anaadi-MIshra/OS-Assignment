#include <stdio.h>         
#include <sys/types.h>          
#include <sys/socket.h>
#include <linux/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define TOTAL_THREADS 54

void  *thread_task(void* data){

int temp = *((int *)data);
printf("%d client \n", temp);
int cs;
    struct sockaddr_in saddr;
    unsigned char buff[1024] = {0};

    cs = socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    saddr.sin_port = htons(5678);

    connect(cs, (struct sockaddr *) &saddr, sizeof(saddr));

   // write(cs, "hi from client\n", 18);
    char i = 0;
    while (1){write(cs, &i, sizeof(i));
    i++;
       sleep(1);
       if(i>=10)break;
       }  // read(cs, buff, 1024);

    printf("Server sent: %s\n", buff);

    close(cs);

    
}

int main(void)
{
    int interval = 1 ;
    pthread_t thread_id[TOTAL_THREADS];
    printf("Creating Threads:\n");

    for(int i =1; i<= TOTAL_THREADS; i++){

        pthread_create(&thread_id[i-1], NULL, thread_task, &interval);
        interval++;
    }

     sleep(10);

    for(int i =1 ; i<=TOTAL_THREADS ; i++){

        pthread_join(thread_id[i-1], NULL);
    }

    sleep(1000);

    return 0;
}
