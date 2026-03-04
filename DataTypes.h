#ifdef DATATYPES_H
#define DATATYPES_H

//struct quản lý Developer
typedef struct{
	char devID[10]; //DEVxxx
	char fullName[50]; //min 2 word
	int bithYear;
	char languages[100];
	float salary; //min $1000
} Developer;

//struct quản lý Project
typedef struct{
	char projectID[10];
	char devID[10]; //must exist in Developer Array
	char projectName[100];
	int duration; //in months
	char startDate[15];
} Project;

#endif