#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int runProgramTimes(char **programWithArgs, int times)
{
    for (int i = 0; i < times; i++)
    {
        int j = fork();
        if (j == 0)
        { // fork içi
            if (execvp(programWithArgs[0], programWithArgs, NULL) < 0)
            {
               
            }
            else
            {
               
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char howTimes[100];
    char program[100];
    char** programWithArgs;

    programWithArgs = malloc(100 * sizeof(char *));
    for (int i = 0; i < 100; i++)
        programWithArgs[i] = malloc(100 * sizeof(char));

    int i = 0;
    for (int j = 1; j < argc; j++)
    {
        if (strstr(argv[j], "-t") != NULL)
        {
            strcpy(howTimes, argv[++j]);
        }
        else
        {
            strcpy(programWithArgs[i], argv[j]);
            i++;
        }
    }
    programWithArgs[i] = NULL;
    int x;
    sscanf(howTimes, "%d", &x);
    runProgramTimes(programWithArgs, x);

    return 0;
}
