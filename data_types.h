#ifndef DATATYPES_H
#define DATATYPES_H
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char devID[10];
    char fullName[50];
    int birthYear;          // Them truong nam sinh
    char languages[100];    // Them truong ngon ngu lap trinh
    double salary;          // Them truong luong thang
    int projectCount;
} Developer;

typedef struct {
    char projectID[10];
    char devID[10];
    char projectName[100];
    int duration;
    char startDate[20];
    int status;             // 1 = Active, 0 = Completed
} Project;
#endif