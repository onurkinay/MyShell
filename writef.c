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

int writeIntoFile(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if (file)
    {
        // file exists and can be opened
        //...
        //  close file when you're done
        fclose(file);
    }
    else
    {
        // file doesn't exists or cannot be opened (es. you don't have access permission)
    }
}

int main(int argc, char const *argv[])
{
    /* code */

    /*Arguman olarak gelen dosya adını alma*/
    char* filename[100];
    for (int i = 0; i < argc; i++)
    {
      if(strstr(argv[i], "-f") != NULL){
       strcpy(filename,argv[i+1]);
      }
    } 
    /*!Arguman olarak gelen dosya adını alma*/

    
    getSystemInfo();
    return 0;
}
