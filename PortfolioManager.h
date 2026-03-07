#ifndef PORTFOLIOMANAGER_H
#define PORTFOLIOMANAGER_H
#include "DataTypes.h"
#include <ctype.h>

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

//Check Input Format 
int isValidDevID(const char* id){
	if(strlen(id) != 6) return 0;//check lengh
	if(strncmp(id, "DEV", 3) != 0) return 0;//check format
	if(!isdigit(id[3]) || !isdigit(id[4]) || !isdigit(id[5])) return 0;// 3 char not number
	return 1;	
}

//Check Duplicate ID
int isDuplicateDevID(const char* id){
	for(int i = 0; i < devCount; i++){
		if(strcmp(devList[i].devID, id) == 0) return 1; //duplicate
	}
	return 0;
}

//Check min 2 wrod have space between words
int isValidName(const char* name){
	int len = strlen(name);
	int spaceCount = 0;
	
	for(int i = 1; i < len - 1; i++){
		if(name[i] == ' ' && name[i-1] != ' '){
			spaceCount++;
		}
	}
	return spaceCount >= 1 ? : 0;
}

#endif
