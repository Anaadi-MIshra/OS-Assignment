#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
  #include <unistd.h>
#define buf_size 20

int main()
{
    int fdr;
    int b[2];int c;
    char buf1[buf_size],buf2[buf_size];
    fdr=open("desd",O_RDONLY);
    if(-1==fdr)
    {

        perror("2:");
        exit(1);
    }
    read(fdr,&b,8);
    printf("it is rec:sent from sen %d, %d\n",b[0],b[1]);
    close(fdr);
    c=b[0]+b[1];
    printf("sum=%d\n",c);
    fdr=open("desd",O_WRONLY);
    if(-1==fdr)
    {
        perror("2:");
        exit(1);
    }
//	printf("c= %d, %p", c,&c);
    write(fdr,&c,4);
	close(fdr);
    return 0;
}
