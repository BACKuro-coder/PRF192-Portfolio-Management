#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include "data_types.h"
#include "product.h"

// Bien toan cuc - Developer & Project
extern Developer* devList;
extern int devCount;
extern Project* projectList;
extern int projectCount;

// Bien toan cuc - Product
extern ProductManager productMgr;

// He thong
void initSystem();
void freeSystem(); 

// Validation functions (dung chung cho nhieu file)
int isValidDevID(const char* id);
int isDuplicateDevID(const char* id);
int isValidName(const char* name);
int isDuplicateProjectID(const char* id);
int isExistingDevID(const char* id);

// Developer CRUD
void addDeveloper();
void searchDeveloper();
void updateDeveloperSalary();
void removeDeveloper();

#endif