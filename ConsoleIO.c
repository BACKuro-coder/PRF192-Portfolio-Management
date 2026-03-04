#include <studio.h>
#include <string.h>
#include <stdlib.h>
#include "ConsoleIO.h"

void printMenu(){
	printf("\n ==== DEVELOPER & PROJECT PROTPOLIO MANAGEMENT ===\n");
	printf("1. Add a new Developer\n");
	printf("2. Search Developer\n");
	printf("3. Assign Project to Developer\n");
	printf("4. Sort Developers by Salary\n");
	printf("5. Save and Exit\n");
	printf("===================================================\n");
}

void getString(const char* prompt, char* buffer, int maxLenght){
	printf("%s", prompt);
	fflusg(stdin);
	fgets(buffer, maxLenght, stdin);
	buffer[strcspn(buffer, "\n")] = 0; // xoa ky tu newline
	
}

//TODO
//implement getValidInt, getValidFloat use while to set right input from user