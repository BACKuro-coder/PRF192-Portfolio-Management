#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "data_types.h"

// Ham load/save Developer tu file nhi phan
int loadDevelopersFromFile(const char* filename, Developer** devs, int* count);
int saveDevelopersToFile(const char* filename, Developer* devs, int count);

// Ham load/save Project tu file nhi phan
int loadProjectsFromFile(const char* filename, Project** projs, int* count);
int saveProjectsToFile(const char* filename, Project* projs, int count);

#endif