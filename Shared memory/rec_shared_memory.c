#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> 
#include<sys/types.h>
#include<sys/shm.h>
int* countr;
int main()
{
    int fd;
    fd=shm_open("/desdshm",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    ftruncate(fd,sizeof(int));
    countr=(int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //*count=0;
    while(1)
    {
        printf("\n Shared mem val: %d ",(*countr));
    }    
    return 0;
}