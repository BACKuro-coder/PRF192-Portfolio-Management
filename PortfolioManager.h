#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H
#include "DataTypes.h"

//manage status system
extern Developer* devList;
extern int devCount;
extern Project* projectList;
ectern int projectCount;

//implement functional 
void innitSystem();
void freeSystem();// avoid memory leak
void addDeveloper();
void searchDeveloper();
void assignProject();
void sortDevelopersBySalary();

#endif
