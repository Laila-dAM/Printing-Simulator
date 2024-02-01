#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct PrintJob {
    int id;
    char fileName[50];
    struct PrintJob *next;
};