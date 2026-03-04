#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "DataTypes.h"

int loadDeveloperFromFile(const char* filename, Developer** devs, int* count);
int saveDelopersToFile(const char* filename, Developer* devs, int count);
//TODO
//add same to Project

#endif