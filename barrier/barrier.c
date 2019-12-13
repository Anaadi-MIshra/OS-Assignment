
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


pthread_barrier_t barr;

void *lcd(void *arg)
{
    printf("lcd init started\n");
    sleep(5);
    printf("lcd init done\n");
    pthread_barrier_wait(&barr);
    printf("lcd function\n");
}

void *serial(void *arg)
{
    printf("serial init started\n");
    sleep(8);
    printf("serial init done\n");
    pthread_barrier_wait(&barr);
    printf("serial function\n");

}

void *network(void *arg)
{
    printf("network init started\n");
    sleep(12);
    printf("network init done\n");
    pthread_barrier_wait(&barr);
    printf("network function\n");

}

void *tempsen(void *arg)
{
    printf("tempsen init started\n");
    sleep(15);
    printf("tempsen init done\n");
    pthread_barrier_wait(&barr);
    printf("temp function\n");

}

int main()
{   
    pthread_t lcd_id, serial_id, network_id, temp_id;
    pthread_barrier_init(&barr, NULL, 4);                  //barrier for all thread init for 4 thread
    pthread_create(&lcd_id, NULL, lcd, NULL);
    pthread_create(&serial_id, NULL, serial, NULL);
    pthread_create(&network_id, NULL, network, NULL);
    pthread_create(&temp_id, NULL, tempsen, NULL);
    pthread_join(lcd_id, NULL);
    pthread_join(serial_id, NULL);
    pthread_join(network_id, NULL);
    pthread_join(temp_id, NULL);
    pthread_barrier_destroy(&barr);
    return 0;
}
