#include <stdio.h>
#include "data_types.h"
#include "assign_project.h"
#include "calculate_experience.h"
#include "group_projects.h"

int main() {

    Developer developerList[MAX] = {
        {"DEV001", "Nguyen Van A", 0},
        {"DEV002", "Tran Thi B", 0}
    };

    Project projectList[MAX];

    int developerCount = 2;
    int projectCount = 0;

    int choice;

    do {
        printf("\n===== PROJECT MANAGEMENT =====\n");
        printf("1. Assign Project to Developer\n");
        printf("2. Calculate Total Experience\n");
        printf("3. Group Projects by Developer\n");
        printf("0. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            assignProjectToDeveloper(projectList, &projectCount,
                                     developerList, developerCount);
            break;

        case 2:
            calculateTotalExperience(projectList, projectCount);
            break;

        case 3:
            groupProjectsByDeveloper(projectList, projectCount,
                                     developerList, developerCount);
            break;

        }

    } while (choice != 0);

    return 0;

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