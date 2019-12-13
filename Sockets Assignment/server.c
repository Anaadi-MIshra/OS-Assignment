#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>


int client=0;
struct timeval  time;
int main()
{

int server_sockfd;
int client_sockfd;


struct sockaddr_in server_address;
struct sockaddr_in client_address;


server_sockfd = socket(AF_INET, SOCK_STREAM,0);

server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
server_address.sin_port = htons(5678);

bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address));
listen(server_sockfd, 100);

printf("SERVER STARTED.\n");
printf("Waiting For Clients..\n");
while(1){


int client_len = sizeof(client_address);
client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_address, &client_len );
char value;

client++;
if(-1 == fork()){
    perror("Forking Error.\n");
    exit(1);
}
if (0==fork()){
while(1 && read(client_sockfd, &value ,sizeof(value) )){

printf("Client no. %d : recieved : %d\n", client, value);
//sleep(1);
//write(client_sockfd, )  
//double millis = gettimeofday(&time, NULL);                                
//if(0==value){
 //   printf("Exiting %d client", client);
    
//}
exit(0);

}

}


else{
close(client_sockfd);
continue;
}

}

return 0;
}
