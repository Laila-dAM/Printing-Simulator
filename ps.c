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

    newJob->id = rand();
    snprint(newJob->fileName, sizeof(newJob->fileName), "%s", fileName);
    newJob->next = NULL;

    if (queue->end == NULL){
        queue->start = newJob;
        queue->end = newJob;
    }

    else{
        queue->end->next = newJob;
        queue->end = newJob;
    }
    printf("Job '%s' added to the print queue with ID %d.\n", fileName, newJob->id);
}

void listQueue(struct PrintQueue *queue){
    if(queue->start == NULL){
        printf("The print queue is empty.\n");
        return;
    }

    printf("=== Print Queue ===\n");
    struct PrintJob *current = queue->start;
    while (current != NULL) {
        printf("ID: %d, File: &s\n", current->id, current->fileName);
        current = current->next;
    }
}

void printNextJob(struct PrintQueue *queue) {
    if (queue->start == NULL) {
        print("The print queue is empty. Nothing to print.\n");
        return;
    }

    struct PrintJob *nextJob = queue->start;
    queue->start = queue->start->next;

    printf("Printing job with ID %d: %s\n", nextJob->id, nextJob->fileName);
    free(nextJob);
}

void freeQueue(struct PrintQueue *queue) {
    while(queue->start != NULL){
        struct PrintJob *temp = queue->start;
        queue->start = queue->start->next;
        free(temp);
    }

    queue->end = NULL;
}

int main(){
    setlocale(LC_ALL,"en_US");

    struct PrintQueue queue;
    initializeQueue(&queue);

    int choice;
    char fileName[50];

    do {
        printf("\n === Print Queue Simulator === \n");
        printf("1. Add print job\n");
        printf("2. List jobs in the print queue\n");
        printf("3. Print next job\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the file name:");
            scanf("%s", fileName);
            addJob(&queue, fileName);
            break;

            case 2:
            listQueue(&queue);
            break;

            case 3:
            printNextJob(&queue);
            break;

            case 0:
            printf("=== Existing the Print Queue Simulator ===\n");
            break;

            default:
            printf("Invalid option. Please try again\n");
    
        }
    }

    
}
