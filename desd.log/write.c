 #include <sys/types.h>
 #include <sys/stat.h>
#include <fcntl.h>
 #include <err.h>
 #include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    fd = open("desd.txt", O_WRONLY | O_CREAT);
if(-1==fd)
{
    perror("error opening the file\n");
   exit(EXIT_FAILURE);
}
 write(fd, "CDACDESD\n", 9);
 close(fd);
return 0;

}
