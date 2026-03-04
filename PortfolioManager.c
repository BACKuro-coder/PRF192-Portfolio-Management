#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PortfolioManager.h"
#include "ConsoleIO.h"

Developer* devList = NULL;
int devCount = 0;
Project* projectList = NULL;
int projectCount = 0;

void initSystem(){
	//call load from FileHelper
	//if file not have, create malloc 
	devList = (Developer*)malloc(sizeof(Developer)* 10); // 10 slots
}

void freeSystem(){
	if(devList != NULL) free(devList);
	if(projectList != NULL) free(projectList);
}

void addDeveloper(){
	//TODO
	//1. Check realloc(), devCount is over array
	//2. Use getString(), getValidFloat() from Console take data
	//3. Check ValidateID() is loop || not
	//4. Save to devList[devCount] and increase devCount++
	print("Adding new developer..\n");
}

//TODO
//implement another functions (search, assign, sort)
