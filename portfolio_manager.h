#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include "data_types.h"

// Bien toan cuc
extern Developer* devList;
extern int devCount;
extern Project* projectList;
extern int projectCount;

// Khai bao ten ham (Khong co ruot code o day)
void initSystem();
void freeSystem(); 

//---For Developer---
void addDeveloper();
void searchDeveloper();          // Tim Developer theo ID hoac Ten
void updateDeveloperSalary();
void removeDeveloper();
void sortDevelopersBySalary();   // Sap xep Developer theo luong giam dan

//---For Project---
void assignProject();            // Gan project cho developer

#endif