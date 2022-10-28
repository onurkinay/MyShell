#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int initShell()
{
    printf("Hello from MyShell");
    return 0;
}

int getUserInput()
{
    char str[20];
    printf("myshell>>>");
    scanf("%[^\n]%*c", str);
    printf("%s\n", str);
}

int runComm(char **commWithArgs)
{
    int i = fork();

    if (i == 0)
    {
        // run command in child fork
        if (execve(commWithArgs[0], commWithArgs, NULL) < 0)
        { // error
            printf("Program is failed\n");
        }
        exit(0); // if child process is done, exit
    }
    else if (i < 0)
    {
        // error while creating fork
        printf("Error 64");
    }
    else
    { // wait for get it done
        wait(NULL);
        return 2;
    }
    return 0;
}

int exitFromShell()
{
    wait(NULL);
    exit(0);
    return 0;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        getUserInput();
    }

    return 0;
}
