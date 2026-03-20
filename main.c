/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include "portfolio_manager.h"
#include "console_io.h"
#include "file_helper.h"
#include "developer_display.h"
#include "project_functions.h"
#include "product_menu.h"

int main(int argc, char *argv[]) {
	int choice;
	
	// Khoi tao he thong: cap phat bo nho va doc file du lieu
	initSystem();
	
	do{
		printMenu();
		choice = getValidInt("Enter your choice (0-10): ", 0, 10);
		
		switch (choice){
			case 1: addDeveloper();
			break;
			case 2: searchDeveloper();
			break;
			case 3: updateDeveloperSalary();
			break;
			case 4: removeDeveloper();
			break;
			case 5: showAllDevelopers();
			break;
			case 6: sortDevelopersBySalary();
			break;
			case 7: assignProject();
			break;
			case 8: calcExperience();
			break;
			case 9: groupProjects();
			break;
			case 10: productMenu();
			break;
			case 0: 
				printf("Saving and exiting..\n");
				// Luu du lieu Developer va Project ra file truoc khi thoat
				saveDevelopersToFile("developers.dat", devList, devCount);
				saveProjectsToFile("projects.dat", projectList, projectCount);
				saveProductToFile(&productMgr, "products.csv");
				break;
		}
	} while(choice != 0);
	
	// Giai phong toan bo bo nho dong truoc khi thoat chuong trinh
	freeSystem();
	
	return 0;
}