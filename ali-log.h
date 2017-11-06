#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>


#define BUFF_LEN 64
#define LOG_MAX 1024
#define LOG_SWITCH "log_switch"
#define LOG_LEVEL "log_level"
#define LOG_CONF "./log.conf"
#define LOG_FILE "./log.txt"
#define ERROR_MASK 1
#define WARN_MASK 2
#define INFO_MASK 4


extern int g_logSwitch,g_logLevel;
extern char msg[LOG_MAX];
//#define ERROR_LOG(desc) SET_ERROR_LOG(__FILE__,__func__,__LINE__,desc)
//#define WARN_LOG(desc) SET_WARN_LOG(__FILE__,__func__,__LINE__,desc)
//#define INFO_LOG(desc) SET_INFO_LOG(__FILE__,__func__,__LINE__,desc)

#define ERROR_LOG(...) \
    memset(msg,0,sizeof(msg));\
    sprintf(msg,__VA_ARGS__);\
    SET_ERROR_LOG(__FILE__,__func__,__LINE__,msg);

#define WARN_LOG(...) \
    memset(msg,0,sizeof(msg));\
    sprintf(msg,__VA_ARGS__);\
    SET_WARN_LOG(__FILE__,__func__,__LINE__,msg);

#define INFO_LOG(...) \
    memset(msg,0,sizeof(msg));\
    sprintf(msg,__VA_ARGS__);\
    SET_WARN_LOG(__FILE__,__func__,__LINE__,msg);


void InitCodeLog();
void WriteLogData(const char *level,const char *file,const char *func,const unsigned int line,const char *desc);
void GetNowTime(char *buf,const int len);


void SET_ERROR_LOG(const char *file,const char *func,const unsigned int line,const char *desc);
void SET_WARN_LOG(const char *file,const char *func,const unsigned int line,const char *desc);
void SET_INFO_LOG(const char *file,const char *func,const unsigned int line,const char *desc);



