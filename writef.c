#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

char* getTime()
{ 
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char* time = asctime(timeinfo);
    time[strcspn(time, "\n")] = 0;
    return time;
}

char *getSystemInfo()
{
    printf("time:%s pid:%d ppid:%d\n",getTime(),getpid(),getppid());
}

int main(int argc, char const *argv[])
{
    /* code */
    getSystemInfo();
    return 0;
}
