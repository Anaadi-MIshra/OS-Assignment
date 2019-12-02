   #include <sys/types.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <stdio.h>
     #include <string.h>



int main(){

int x=4;

    while(x--){
     unsigned char temp[100] = {0};
     unsigned char *buff[10] ={NULL};
     
     unsigned char path[20] = "/bin/";
    
     printf("Next Command:\n");
     scanf(" %[^\n]s", temp);
     
          if(!strncmp(temp, "exit", 4))
     {
          exit (0);

     }
     

     else strcat(path, temp);

     //printf("02 %s\n", path);
     
     char* token = strtok(path, " ");
     int i=0;

    while ( token != NULL) { 
     
          buff[i] = token;
         // printf("%d %s\n",i, buff[i]);
          i++;
        token = strtok(NULL, " "); 

           }
           buff[i] = NULL;


    int x = fork();
     if(-1 == x) {
          perror("forking failed\n");
          exit(1);
     }
     if(0 == x)
     {
        //  printf("CHILD HERE\n");
         // close(pipefd[1]);
            //unsigned char command[20];
         // read( pipefd[0], command, 20);
          //printf("command read : %s\n", command);
         execvp(buff[0],buff);
          printf("Faulty Command\n");
        
          exit(1);
     }

     else
     {
   //       printf("PARENT HERE\n");
  //       // close(pipefd[0]);
       //  write(pipefd[1], path, strlen(path));
       //  printf("Command Sent to child\n"); 
  //  
     sleep(1);
 }

    }
     return 0;
}


     
