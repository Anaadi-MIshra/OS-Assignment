   #include <sys/types.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <stdio.h>
     #include <string.h>

void parse_command(unsigned char **array){

for ()



}


int main(){

    
    pid_t parent, child;
   

    while(1){
     unsigned char *temp ;
     unsigned char buff[10] ;
     unsigned char path[20] = "/bin/";
      int pipefd[2];
     pipe(pipefd);
     printf("Next Command:\n");
     temp = fgets();
     
     if(!strncmp(temp, "exit", 4))
     {
          exit (0);
     }

     else strcat(path, temp);

     printf ("%s\n", path);

     int x = fork();
     if(-1 == x) {
          perror("forking failed\n");
          exit(1);
     }
     if(0 == x)
     {
          printf("CHILD HERE\n");
          close(pipefd[1]);
            unsigned char command[20];
          read( pipefd[0], command, 20);
          printf("command read : %s\n", command);
          execl(command, command, NULL);
          printf("executed\n\n\n");
          exit(0);
     }

     else
     {
          printf("PARENT HERE\n");
          close(pipefd[0]);
         write(pipefd[1], path, strlen(path));
         printf("Command Sent to child\n"); 
     }
     sleep(1);

    }
     return 0;
}


     