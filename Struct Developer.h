#ifndef DEVELOPER_H
#define DEVELOPER_H

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

extern Developer *developerList;
extern int developerCount;
extern int capacity;

#endif