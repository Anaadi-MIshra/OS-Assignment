            
 #include <fcntl.h>            
#include <unistd.h>
#include<stdio.h>
 #include <sys/types.h>



int main()
{
    int pfd[2];
     // pid_t;
      int id ;
    pipe[pfd];
      unsigned char buffer[20];
      id =fork();
      if(0==id)
      {
          close(pfd[1]);
          read(pfd[0],20);
          printf("child:recv:from parent");
      }
      else
      {
          close(pfd[0]);
      write(pfd[1],"hello\n",6);
}
      return 0;
}
