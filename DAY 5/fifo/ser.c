#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
  #include <unistd.h>
#define buf_size 20
int main()
{
    int a[2]={5,4};
    int d;
    int fds;
    char buf1[buf_size],buf2[buf_size];
    fds=open("desd",O_WRONLY);
    if(-1==fds)
    {
        perror("1:");
        exit(1);
    }
    write(fds,&a,8);
    close(fds);
   
    fds=open("desd",O_RDONLY);
    if(-1==fds)
    {
        perror("2:");
        exit(1);
    }
    read(fds,&d,4);
    printf("sent from rec:%d\n",d);

    close(fds);
    return 0;
}
