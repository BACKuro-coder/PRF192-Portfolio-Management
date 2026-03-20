#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char devID[10];
    char fullName[50];
    int birthYear;
    char languages[50];
    double salary;
    int projectCount;
} Developer;

Developer *developerList = NULL;
int developerCount = 0;
int capacity = 0;