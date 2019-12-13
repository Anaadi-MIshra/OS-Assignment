#include<stdio.h>
#include<pthread.h>
void* rtc_thread(void* data);
int main()
{
    pthread_t id_rtc;
    printf("before thread\n");
    pthread_create(&id_rtc,NULL,rtc_thread,NULL);
    printf("after thread\n");
    pthread_join(id_rtc,NULL);
    return 0;
}
void* rtc_thread(void* data)
{
    printf("rtc thread execution succesfull\n");
}
