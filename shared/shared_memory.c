#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/mman.h>
#include <sys/stat.h> 
#include<sys/types.h>
#include<sys/shm.h>
int* count;
int main()
{
    int fd;
    fd=shm_open("/desdshm",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    ftruncate(fd,sizeof(int));
    count=(int*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    *count=0;
    while(1)
    {
        (*count)++;
        sleep(1);
        
    }    
    return 0;
}
