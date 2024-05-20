#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define size 10

struct pclient {
    char name[50];
    int time;
};

struct pstack {
    struct pclient data[size];
    int start;
    int end;
};

struct pstack stack;

int start = 0;
int end = 0;

void quere() {
    if (stack.end == size) {
        printf("The quere is full, wait outside.\n\n");
        system("pause");
    }
    else {
        printf("Enter your name:");
        scanf("%s", stack.data[stack.end].name);
        time_t tempo = time(NULL);
        //time = &tempo;
        stack.data[stack.end].time = %tempo;
        //strcpy(stack.data[stack.end].time, "time");
        stack.end++;
    }
}

void unquere() {
    if(stack.end == stack.start) {
        printf("The quere is empty.\n");
        system("pause");
    }
    else {

        for (int i = 0;i<size; i++) {
            strcpy(stack.data[i].name, stack.data[stack.start+1].name);
            stack.data[i] = stack.data[stack.start+1];
            stack.end--;
        }
    }
}

void show_quere() {
    printf("[");
    for (int i=0;i<size;i++) {
        printf("%s, ", stack.data[i].name);
    }
    printf("]\n\n");
}