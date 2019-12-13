
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int num = 1;
pthread_rwlock_t count;

void *lcd(void *arg)
{
    pthread_rwlock_rdlock(&count);
    printf("lcd thread\n");
    printf("print lcd value\n");
    pthread_rwlock_unlock(&count);
}

void *serial(void *arg)
{
    pthread_rwlock_rdlock(&count);
    printf("serial thread\n");
    printf("print serial value\n");
    pthread_rwlock_unlock(&count);
}

void *count_thread(void *arg)
{
    pthread_rwlock_wrlock(&count);
    printf("count thread\n");
    num++;
    printf("Inc num is:%d\n",num);
    pthread_rwlock_unlock(&count);
}

int main(int argc, char const *argv[])
{   
    pthread_t lcd_id, serial_id, countTrd_id;
    pthread_rwlock_init(&count, NULL);                  
    pthread_create(&lcd_id, NULL, lcd, NULL);
    pthread_create(&serial_id, NULL, serial, NULL);
    pthread_create(&countTrd_id, NULL, count_thread, NULL);
    pthread_join(lcd_id, NULL);
    pthread_join(serial_id, NULL);
    pthread_join(countTrd_id, NULL);
    pthread_rwlock_destroy(&count);
    return 0;
}
