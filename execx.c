#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
     
    char howTimes[100];
    char program[100];
    for (int i = 1; i < argc; i++)
    {
        if (strstr(argv[i], "-t") != NULL)
        {
            strcpy(howTimes, argv[++i]);
        }else{
            strcpy(program, argv[i]);
        }
    }
  
    return 0;
}
