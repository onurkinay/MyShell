#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int initShell()
{
}

int runComm()
{
    char *Args[3];

    Args[0] = "cat";
    Args[1] = "main.c";
    Args[2] = NULL;

    int i = fork();

    if (i == 0)
    {
        printf("Program is started to work\n");
        if (execve("/bin/cat", Args,NULL) < 0)
        {
            printf("Program is failed\n");
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        return 2;
    }
    return 0;
}

int exitFromShell()
{
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("Hello world. Test\n");
    runComm();
    return 0;
}
