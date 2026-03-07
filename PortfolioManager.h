#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H

#include "DataTypes.h"

// Biến toàn cục
extern Developer* devList;
extern int devCount;
extern Project* projectList;
extern int projectCount;

// Khai báo tên hàm (Không có ruột code ở đây)
void initSystem();
void freeSystem(); 


//---For Developer---
void addDeveloper();
void searchDeveloperByID();
void searchDeveloperByName();
void updateDeveloperSalary();
void removeDeveloper();

#endif