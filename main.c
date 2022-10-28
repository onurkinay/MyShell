#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAXCHAR 1000
#define MAXARGS 100

int initShell()
{
    printf("Hello from MyShell");
    return 0;
}

int getUserInput(char *input)
{
    char str[20];
    printf("myshell>>>");
    fgets(str, MAXCHAR, stdin);
    if (str[0] != '\n' && str[1] != '\0')//check empty
    {
        str[strcspn(str, "\n")] = 0;
        strcpy(input, str);
        return 0;
    }
    else
    {
        printf("No command.\n");
        return 1;
    }
    
}

int sepByInput(char *str, char **passed){
    int str_size = strlen(str);
	char delim[] = " ";

	char *ptr = strtok(str, delim);
    int i = 0; 
	while(ptr != NULL)
	{ 
        passed[i] = ptr;
		ptr = strtok(NULL, delim);
        i++;
	}

    passed[i] = NULL;
    return 0;

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
    char inputFromUser[MAXCHAR];
    char *Args[MAXARGS];

    while (1)
    {
        if (getUserInput(inputFromUser))
            continue;

        sepByInput(inputFromUser, Args);
        
        
        
        
    }

    return 0;
}
