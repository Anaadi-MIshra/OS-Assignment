   #include <sys/types.h>
     #include <unistd.h>
     #include <stdlib.h>
     #include <stdio.h>
     #include <string.h>



int main(){



    while(1){
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

     
     
     char* token = strtok(path, " ");
     int i=0;

    while ( token != NULL) { 
     
          buff[i] = token;
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
        execvp(buff[0],buff);
          printf("Faulty Command\n");
        
          exit(1);
     }

     else
     {
  
     sleep(1);
 }

    }
     return 0;
}


     
