#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

char *getTime()//sistemden tarih bilgisini al
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char *time = asctime(timeinfo);
    time[strcspn(time, "\n")] = 0;
    return time;
}

int writeIntoFile(char *filename)//process ve tarih bilgilerini dosyaya kaydet
{
    FILE *fp = fopen(filename, "ab+"); // creates file if no exists and open append mode
    if (fp)
    {
        fprintf(fp, "time:%s pid:%d ppid:%d\n", getTime(), getpid(), getppid());
        fclose(fp);
    }
    else
    {
        printf("Error about file");
    }
}

int main(int argc, char const *argv[])
{
    /*Arguman olarak gelen dosya adını alma*/
    char filename[100];
    for (int i = 0; i < argc; i++)
    {
        if (strstr(argv[i], "-f") != NULL)
        {
            strcpy(filename, argv[i + 1]);
        }
    }
    /*!Arguman olarak gelen dosya adını alma*/

    writeIntoFile(filename);
    return 0;
}
