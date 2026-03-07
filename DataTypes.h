#ifndef DATATYPES_H
#define DATATYPES_H

// Struct quản lý Developer
typedef struct {
    char devID[10];       // DEVxxx
    char fullName[50];    // min 2 words
    int birthYear;        // Đã sửa lỗi chính tả ở đây
    char languages[100];
    float salary;         // min $1000
} Developer;

// Struct quản lý Project
typedef struct {
    char projectID[10];
    char devID[10];       // must exist in Developer Array
    char projectName[100];
    int duration;         // in months
    char startDate[15];
} Project;

#endif