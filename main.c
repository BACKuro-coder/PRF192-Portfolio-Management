#include <stdio.h>
#include <stdlib.h>
#include "PortfolioManager.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	
	initSystem(); //create memory. read file
	
	do{
		printMenu();
		choice = getValidInt("Enter your choice (1-5): ", 1, 5);
		
		switch (choice){
			case 1: addDeveloper();
			break;
			case 2: searchDeveloper();
			break;
			case 3: assignProject();
			break;
			case 4: sortDevelopersBySalary();
			break;
			case 5: 
				printf("Saving and exiting..\n");
				//function save from FileHelper
				break;
		}
	} while(choice!= 5);
	freeSystem();
	
	
	return 0;
}