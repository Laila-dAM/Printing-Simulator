#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct PrintJob {
    int id;
    char fileName[50];
    struct PrintJob *next;
};

struct PrintQueue {
    struct PrintJob *start;
    struct PrintJob *end;
};

void initializeQueue(struct PrintQueue *queue) {
    queue->start = NULL;
    queue->end = NULL;
}

void addJob(struct PrintQueue *queue, const char *fileName){
    struct PrintJob *newJob = (struct PrintJob *)malloc(sizeof(struct PrintJob));
    if (newJob == NULL){
        perror("Error allocating memory for print job");
        exit(EXIT_FAILURE);
    }
}