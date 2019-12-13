#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before fork\n");
    id = fork();

    if (0 == id)
    {
        printf("Child: PID: %d PPID: %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent: PID: %d PPID: %d\n", getpid(), getppid());
        sleep(30);
    }

    printf("After fork\n");
    return 0;
}
