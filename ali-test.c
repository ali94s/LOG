#include<stdio.h>
#include<string.h>
#include"ali-log.h"
#include<pthread.h>
#include<unistd.h>

void *func()
{
    while(1)
    {
        ERROR_LOG("thread test error");
        WARN_LOG("thread test warn");
        INFO_LOG("thread test info");
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
        ERROR_LOG("this is an error test");
        WARN_LOG("this is a warn test");
        INFO_LOG("this is an info test");
        sleep(2);
   }
    return 0;
}

