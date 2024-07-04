#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct pclient
{
    char name[50];
    char time[6];
};

struct pquere
{
    struct pclient data[size];
    int start;
    int end;
};

//Global variables
struct pquere fila;
int start = 0;
int end = 0;

//Prototipation
void quere();
void unquere();
void show_quere();
void show_menu1();

int main()
{
    setlocale(LC_ALL, "portuguese");
    int op = 1;
    while (op != 0)
    {
        system("cls");
        show_menu1();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            quere();
            break;
        case 2:
            unquere();
            break;
        case 3:
            show_quere();
            break;
        }
    }
    return (0);
}

void quere()
{
    if (fila.end == size)
    {
        printf("The quere is full, wait outside.\n\n");
        system("pause");
    }
    else
    {
        printf("Enter your name:");
        scanf("%s", fila.data[fila.end].name);
        printf("Enter the time in that client came:");
        scanf("%s", fila.data[fila.end].time);
        fila.end++;
    }
}

void unquere()
{
    if (fila.end == fila.start)
    {
        printf("The quere is empty.\n");
        system("pause");
    }
    else
    {
        for (int i=0; i< size; i++)
        {
            strcpy(fila.data[i].name, fila.data[i + 1].name);
            strcpy(fila.data[i].time, fila.data[i + 1].time);
            fila.end--;
        }
    }
}

void show_quere()
{
    printf("");
    for (int i = 0; i < size; i++)
    {
        printf("Cliente %s,", fila.data[i].name);
        printf("came at %s time \n", fila.data[i].time);
    }
    printf("]\n\n");
}

void show_menu1()
{
    printf("Choole a alternative\n\n");
    printf("1 - Queue in a value\n");
    printf("2 - Unqueue out a value\n");
    printf("3 - Show queue\n");
    printf("0 - Quit\n");
}
