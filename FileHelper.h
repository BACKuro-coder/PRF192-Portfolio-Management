#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "DataTypes.h"

int loadDevelopersFromFile(const char* filename, Developer** devs, int* count);
int saveDevelopersToFile(const char* filename, Developer* devs, int count);
//TODO
//add same to Project

#endif