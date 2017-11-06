#include "ali-log.h"

int g_logSwitch=0;
int g_logLevel=0;

void InitCodeLog()
{
    char buffer[BUFF_LEN];
    FILE *fp;
    int confRet;
    fp=fopen(LOG_CONF,"r");
    if(NULL==fp)
    {
        perror("open logconf failure");
        return;
    }
    fgets(buffer,BUFF_LEN,fp);
    confRet=strncmp(buffer,LOG_SWITCH,strlen(LOG_SWITCH));
    if(confRet == 0)
    {
        g_logSwitch=buffer[strlen(LOG_SWITCH)+1]-'0';
    }
    if(g_logSwitch == 0)
    {
        fclose(fp);
        return;
    }
    fgets(buffer,BUFF_LEN,fp);
    confRet=strncmp(buffer,LOG_LEVEL,strlen(LOG_LEVEL));
    if(confRet == 0)
    {
        g_logLevel = buffer[strlen(LOG_LEVEL)+1]-'0';
    }
    fclose(fp);
}

void GetNowTime(char *buf,const int len)
{
    time_t rawTime;
    struct tm *timeInfo;
    time(&rawTime);
    timeInfo=localtime(&rawTime);
    strftime(buf,len,"%Y-%m-%d %I:%M:%S",timeInfo);
}

void WriteLogData(const char *level,const char *file,const char *func,const unsigned int line,const char *desc)
{
    FILE *fp;
    char *nowTime;
    char timeBuf[50];
    fp=fopen(LOG_FILE,"a+");
    if(NULL==fp)
    {
        perror("open logfile failure");
        return;
    }
    GetNowTime(timeBuf,50);
    fprintf(fp,"%s[%lu] %s %s->%s->%d:%s\n",level,getpid(),timeBuf,file,func,line,desc);
    fflush(fp);
    fclose(fp);
}

void SET_ERROR_LOG(const char *file,const char *func,const unsigned int line,const char *desc)
{
    if(g_logSwitch == 1)
    {
        if((g_logLevel & ERROR_MASK)!=0)
        {
            WriteLogData("ERROR",file,func,line,desc);
        }
    }
}


void SET_WARN_LOG(const char *file,const char *func,const unsigned int line,const char *desc)
{
    if(g_logSwitch == 1)
    {
        if((g_logLevel & WARN_MASK)!=0)
        {
            WriteLogData("WARN",file,func,line,desc);
        }
    }
}


void SET_INFO_LOG(const char *file,const char *func,const unsigned int line,const char *desc)
{
    if(g_logSwitch == 1)
    {
        if((g_logLevel & INFO_MASK)!=0)
        {
            WriteLogData("INFO",file,func,line,desc);
        }
    }

}




