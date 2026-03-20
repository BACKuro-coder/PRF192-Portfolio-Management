#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_types.h"
#include "console_io.h"
#include "portfolio_manager.h"
#include "project_functions.h"

// ================= HAM ASSIGN PROJECT =================
// Gan project cho developer: validate Project ID unique + Developer ID ton tai
void assignProject() {
    if (devCount == 0) {
        printf("The developer list is empty. Please add a developer first.\n");
        return;
    }
    
    printf("\n--- Assign Project to Developer ---\n");
    
    // Cap phat them bo nho cho 1 project moi
    Project* temp = realloc(projectList, (projectCount + 1) * sizeof(Project));
    if (temp == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    projectList = temp;
    
    // Nhap va validate Project ID - phai la duy nhat
    do {
        getString("Enter Project ID: ", projectList[projectCount].projectID, 10);
        if (isDuplicateProjectID(projectList[projectCount].projectID)) {
            printf("Error: Project ID '%s' already exists. Please enter a unique ID.\n", 
                   projectList[projectCount].projectID);
        } else {
            break;
        }
    } while (1);
    
    // Nhap va validate Developer ID - phai ton tai trong danh sach
    int devIndex = -1;
    do {
        getString("Enter Developer ID (must exist): ", projectList[projectCount].devID, 10);
        // Tim developer trong danh sach
        for (int i = 0; i < devCount; i++) {
            if (strcmp(devList[i].devID, projectList[projectCount].devID) == 0) {
                devIndex = i;
                break;
            }
        }
        if (devIndex == -1) {
            printf("Error: Developer ID '%s' not found. Please enter a valid Developer ID.\n", 
                   projectList[projectCount].devID);
        }
    } while (devIndex == -1);
    
    // Nhap thong tin project
    getString("Enter Project Name: ", projectList[projectCount].projectName, 100);
    projectList[projectCount].duration = getValidInt("Enter Duration (months, 1-120): ", 1, 120);
    getString("Enter Start Date (dd/mm/yyyy): ", projectList[projectCount].startDate, 20);
    projectList[projectCount].status = getValidInt("Enter Status (1: Active, 0: Completed): ", 0, 1);
    
    // Tang so project cua developer tuong ung
    devList[devIndex].projectCount++;
    
    projectCount++;
    printf("Project assigned successfully to %s!\n", devList[devIndex].fullName);
}

// ================= HAM CALCULATE TOTAL EXPERIENCE =================
void calcExperience() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }
    if (projectCount == 0) {
        printf("No projects assigned yet.\n");
        return;
    }
    
    char searchID[10];
    int totalDuration = 0;
    int devFound = 0;
    getString("Enter Developer ID to calculate experience: ", searchID, 10);
    
    // Kiem tra Developer co ton tai khong
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, searchID) == 0) {
            devFound = 1;
            printf("Developer: %s (%s)\n", devList[i].fullName, devList[i].devID);
            break;
        }
    }
    if (!devFound) {
        printf("Error: Developer with ID '%s' not found.\n", searchID);
        return;
    }
    
    // Tinh tong duration cua tat ca project
    for (int i = 0; i < projectCount; i++) {
        if (strcmp(projectList[i].devID, searchID) == 0) {
            totalDuration += projectList[i].duration;
        }
    }
    printf("Total project experience: %d months\n", totalDuration);
}

// ================= HAM GROUP PROJECTS BY DEVELOPER =================
void groupProjects() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }
    
    printf("\n--- Projects Grouped by Developer ---\n");
    for (int i = 0; i < devCount; i++) {
        printf("\nDeveloper: %s - %s\n", devList[i].devID, devList[i].fullName);
        printf("Projects:\n");
        
        int found = 0;
        for (int j = 0; j < projectCount; j++) {
            if (strcmp(projectList[j].devID, devList[i].devID) == 0) {
                printf("   %s - %s (%d months, %s)\n",
                       projectList[j].projectID,
                       projectList[j].projectName,
                       projectList[j].duration,
                       projectList[j].status == 1 ? "Active" : "Completed");
                found = 1;
            }
        }
        if (!found) {
            printf("   No projects assigned\n");
        }
    }
}
