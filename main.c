#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAXCHAR 1000
#define MAXARGS 100

int initShell() // karşılama mesajı
{
    printf("Hello from MyShell\n");
    return 0;
}

int getUserInput(char *input) // kullanıcıdan komut al ve char array'e aktar
{
    char str[20];

    printf("myshell>>>");
    fgets(str, MAXCHAR, stdin);
    if (str[0] != '\n' && str[1] != '\0') // check empty
    {
        str[strcspn(str, "\n")] = 0;
        strcpy(input, str);
        return 0;
    }
    else //komut girmeden Enter derse uyarsın
    {
        printf("Komut Girmediniz\n");
        return 1;
    }
}

int sepByInput(char *str, char **passed) // komut satırını boşluklarla diziye çevir
{
    int str_size = strlen(str); // komut satırı uzunluğu
    char delim[] = " ";         // ayırıcı karakter

    char *ptr = strtok(str, delim); // kamut satını arraye çevir
    int i = 0;
    while (ptr != NULL) // arrayi tek tek passed pointera aktar
    {
        passed[i] = ptr;
        ptr = strtok(NULL, delim);
        i++;
    }

    passed[i] = NULL; // komut satırını NULL yap
    return 0;
}

int runComm(char **commWithArgs) // komut çalıştır
{
    int i = fork(); // child process çalıştır

    if (i == 0)
    {
        // child process içi
        if (execvp(commWithArgs[0], commWithArgs, NULL) < 0)
        { // hatalı girdi
            printf("yanlis komut girdiniz\n");
        }
        exit(0); // if child process is done, exit
    }
    else if (i < 0)
    {
        // child process çalışmazsa
        printf("Komut calistirilirken hata");
    }
    else
    { // komutun işlemesini bitirmesini bekle
        wait(NULL);
        return 2;
    }
    return 0;
}

int exitFromShell() // komut istemcisinden çık
{
    wait(NULL);
    exit(0);
    return 0;
}

int specialComms(char **commWithArgs) // myshellin kendi komutları
{
    int specialComms = 1;
    char *specialCommsList[specialComms];
    int i = 0;
    int whichOne = 0;

    specialCommsList[0] = "exit";

    for (i = 0; i < specialComms; i++) // kullanıcının girdiği komut özel bir komut mu??
    {
        if (strcmp(commWithArgs[0], specialCommsList[i]) == 0)
        {
            whichOne = i + 1;
            break;
        }
    }

    switch (whichOne)
    {
    case 1: // exit
        exitFromShell();
        break;
    default: //özel komut değilse direk çalıştır
        runComm(commWithArgs);
        break;
    }
}

int main(int argc, char const *argv[])
{
    char inputFromUser[MAXCHAR];
    char *Args[MAXARGS];
    initShell();
    while (1)//sonsuz döngü
    {
        if (getUserInput(inputFromUser))//kullanıcının komut girmesini bekle, boş girerse tekrar girmesini bekle
            continue;

        sepByInput(inputFromUser, Args);
        specialComms(Args);
    }

    return 0;
}
