/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include "portfolio_manager.h"
#include "console_io.h"
#include "file_helper.h"

int main(int argc, char *argv[]) {
	int choice;
	
	// Khoi tao he thong: cap phat bo nho va doc file du lieu
	initSystem();
	
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
				// Luu du lieu Developer va Project ra file truoc khi thoat
				saveDevelopersToFile("developers.dat", devList, devCount);
				saveProjectsToFile("projects.dat", projectList, projectCount);
				break;
		}
	} while(choice!= 5);
	
	// Giai phong toan bo bo nho dong truoc khi thoat chuong trinh
	freeSystem();
	
	return 0;
}