       #include <sys/types.h>
       #include <unistd.h>
        #include <stdio.h>


int main()
{
    pid_t parent, child;
    pid_t x = 3;
    
 
    printf("%d\n", x);
    printf("FORKING STARTS!\n");

    parent = getpid();
    child = getppid();

    printf("Parent id before forking %d\n Child id before forking %d\n", parent, child);
   x= fork();
	
	printf("fork return value %d\n",x);
    parent = getpid();
    child = getppid();

     printf("Parent id after forking %d\n Child id after forking %d\n", parent, child);
    
    printf("\n\n");


}
