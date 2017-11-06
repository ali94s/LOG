#include<stdio.h>
#include<string.h>
#include"ali-log.h"
#include<pthread.h>
#include<unistd.h>
int i=0;
void *func()
{
    while(1)
    {
        ERROR_LOG("ERROR thread count =%d",i++);
        WARN_LOG("WARN thread count = %d",i++);
        INFO_LOG("INFO thread count = %d",i++);
        sleep(3);
    }
}

int main()
{
    InitCodeLog();
    //printf("g_logSwitch=%d,g_logLevel=%d\n",g_logSwitch,g_logLevel);
    pthread_t thread_one;
    pthread_create(&thread_one,NULL,func,NULL);
   while(1)
   {
        ERROR_LOG("ERROR main count = %d",i++);
        WARN_LOG("WARN main count=%d",i++);
        INFO_LOG("INFO main count=%d",i++);
        sleep(2);
   }
    return 0;
}

