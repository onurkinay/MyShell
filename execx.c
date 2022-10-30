#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int runProgramTimes(char *program, int times)
{
}

int main(int argc, char const *argv[])
{

    char howTimes[100];
    char program[100];
    char programWithArgs[100][100];
   
    int i = 0;
    for (int j = 1; j < argc; j++)
    {
        if (strstr(argv[j], "-t") != NULL)
        {
            strcpy(howTimes, argv[++j]);
        }else{
            strcpy(programWithArgs[i], argv[j]);
            i++;
        }
    } 

    printf("%s\n", howTimes);
    for (int k = 0; k < i; k++)
    {
        printf("%s\n", programWithArgs[k]);
    }

    return 0;
}
