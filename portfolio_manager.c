#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_types.h"
#include "console_io.h"
#include "portfolio_manager.h"
#include "file_helper.h"

// Cap phat bien toan cuc
Developer* devList = NULL;
int devCount = 0;
Project* projectList = NULL;
int projectCount = 0;

// Khoi tao he thong: doc du lieu tu file khi chuong trinh bat dau
void initSystem() {
    // Thu load Developer tu file nhi phan
    if (loadDevelopersFromFile("developers.dat", &devList, &devCount)) {
        printf("Loaded %d developer(s) from file.\n", devCount);
    } else {
        printf("No existing developer data found. Starting fresh.\n");
    }
    
    // Thu load Project tu file nhi phan
    if (loadProjectsFromFile("projects.dat", &projectList, &projectCount)) {
        printf("Loaded %d project(s) from file.\n", projectCount);
    } else {
        printf("No existing project data found. Starting fresh.\n");
    }
}

// Giai phong toan bo bo nho dong truoc khi thoat
void freeSystem() {
    if (devList != NULL) {
        free(devList);
        devList = NULL;       // Gan NULL sau khi free de tranh loi truy cap vung nho da giai phong
    }
    if (projectList != NULL) {
        free(projectList);
        projectList = NULL;   // Gan NULL sau khi free
    }
}

// ================= CAC HAM VALIDATE =================
int isValidDevID(const char* id) {
    if (strlen(id) != 6) return 0; 
    if (strncmp(id, "DEV", 3) != 0) return 0; 
    if (!isdigit(id[3]) || !isdigit(id[4]) || !isdigit(id[5])) return 0; 
    return 1; 
}

int isDuplicateDevID(const char* id) {
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, id) == 0) return 1; 
    }
    return 0; 
}

int isValidName(const char* name) {
    int len = strlen(name);
    int spaceCount = 0;
    for (int i = 1; i < len - 1; i++) {
        if (name[i] == ' ' && name[i-1] != ' ') spaceCount++;
    }
    return spaceCount >= 1 ? 1 : 0;
}

// Kiem tra Project ID co trung khong
int isDuplicateProjectID(const char* id) {
    for (int i = 0; i < projectCount; i++) {
        if (strcmp(projectList[i].projectID, id) == 0) return 1; // Trung ID
    }
    return 0; // Khong trung
}

// Kiem tra Developer ID co ton tai khong
int isExistingDevID(const char* id) {
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, id) == 0) return 1; // Tim thay
    }
    return 0; // Khong ton tai
}

// ================= HAM ADD DEVELOPER =================
void addDeveloper() {
    printf("\n--- Adding new developer ---\n");

    Developer* temp = realloc(devList, (devCount + 1) * sizeof(Developer));
    if (temp == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    devList = temp;

    do {
        getString("Enter Developer ID (DEVxxx): ", devList[devCount].devID, 10);
        if (!isValidDevID(devList[devCount].devID)) {
            printf("Error: ID must be in format 'DEVxxx' (e.g., DEV001).\n");
        } else if (isDuplicateDevID(devList[devCount].devID)) {
            printf("Error: This ID already exists. Please enter a unique ID.\n");
        } else {
            break; 
        }
    } while (1);

    do {
        getString("Enter Full Name (min 2 words): ", devList[devCount].fullName, 50);
        if (!isValidName(devList[devCount].fullName)) {
            printf("Error: Name must contain at least 2 words.\n");
        } else {
            break;
        }
    } while (1);

    devList[devCount].birthYear = getValidInt("Enter Birth Year (1960 - 2005): ", 1960, 2005);
    getString("Enter Programming Languages: ", devList[devCount].languages, 100);
    devList[devCount].salary = getValidFloat("Enter Monthly Salary (min $1000): ", 1000.0f);

    devCount++;
    printf("Successfully added developer: %s!\n", devList[devCount-1].fullName);
}

// ================= CAC HAM SEARCH =================
void searchDeveloperByID() {
    char searchID[10];
    getString("Enter Developer ID to search (e.g., DEV001): ", searchID, 10);
    
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, searchID) == 0) {
            printf("\n--- Developer Found ---\n");
            printf("ID: %s | Name: %s | Year: %d | Lang: %s | Salary: $%.2f\n",
                   devList[i].devID, devList[i].fullName, devList[i].birthYear,
                   devList[i].languages, devList[i].salary);
            return; 
        }
    }
    printf("Developer with ID '%s' not found.\n", searchID);
}

void searchDeveloperByName() {
    char searchName[50];
    int found = 0;
    getString("Enter Developer Name to search: ", searchName, 50);
    
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < devCount; i++) {
        if (strstr(devList[i].fullName, searchName) != NULL) {
            printf("ID: %s | Name: %s | Year: %d | Lang: %s | Salary: $%.2f\n",
                   devList[i].devID, devList[i].fullName, devList[i].birthYear,
                   devList[i].languages, devList[i].salary);
            found = 1;
        }
    }
    if (found == 0) {
        printf("No developer found matching name '%s'.\n", searchName);
    }
}

void searchDeveloper() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }
    printf("\n--- Search Options ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    
    int choice = getValidInt("Enter your choice (1-2): ", 1, 2);
    if (choice == 1) searchDeveloperByID();
    else searchDeveloperByName();
}

// ================= HAM UPDATE SALARY =================
void updateDeveloperSalary() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }

    char searchID[10];
    getString("\nEnter Developer ID to update salary (e.g., DEV001): ", searchID, 10);

    for (int i = 0; i < devCount; i++) {
        // Tim thay Developer khop ID
        if (strcmp(devList[i].devID, searchID) == 0) {
            printf("Found Developer: %s | Current Salary: $%.2f\n", devList[i].fullName, devList[i].salary);
            
            // Goi ham bat nhap lai neu luong < 1000
            devList[i].salary = getValidFloat("Enter new Monthly Salary (min $1000): ", 1000.0f);
            
            printf("Salary for %s updated successfully to $%.2f!\n", devList[i].fullName, devList[i].salary);
            return; // Cap nhat xong thi thoat ham
        }
    }
    
    // Neu chay het vong lap ma khong return nghia la khong tim thay
    printf("Error: Developer with ID '%s' not found.\n", searchID);
}

// ================= HAM REMOVE DEVELOPER =================
void removeDeveloper() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }

    char searchID[10];
    getString("\nEnter Developer ID to remove: ", searchID, 10);

    int devIndex = -1;
    // 1. Tim vi tri (index) cua Developer trong mang
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, searchID) == 0) {
            devIndex = i;
            break;
        }
    }

    // Neu khong tim thay
    if (devIndex == -1) {
        printf("Error: Developer with ID '%s' not found.\n", searchID);
        return;
    }

    // 2. Kiem tra xem Developer co dang vuong Project ACTIVE nao khong
    // Chi cam xoa neu project co status == 1 (dang hoat dong)
    for (int i = 0; i < projectCount; i++) {
        if (strcmp(projectList[i].devID, searchID) == 0 && projectList[i].status == 1) {
            printf("Error: Cannot remove %s. They are actively assigned to project '%s'.\n", 
                   devList[devIndex].fullName, projectList[i].projectID);
            return; // Dang co project active thi CAM xoa, dung ham ngay
        }
    }

    // 3. Tien hanh xoa (Dich chuyen cac phan tu phia sau len truoc 1 bac)
    printf("Removing developer: %s...\n", devList[devIndex].fullName);
    for (int i = devIndex; i < devCount - 1; i++) {
        devList[i] = devList[i + 1];
    }
    devCount--; // Giam so luong di 1
    
    // 4. Cat giam bo nho (realloc) de toi uu RAM
    if (devCount > 0) {
        Developer* temp = realloc(devList, devCount * sizeof(Developer));
        if (temp != NULL) devList = temp;
    } else {
        free(devList);
        devList = NULL;
    }

    printf("Developer removed successfully.\n");
}

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

// ================= HAM SORT DEVELOPERS BY SALARY =================
// Sap xep Developer theo luong giam dan bang Bubble Sort
void sortDevelopersBySalary() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }
    
    // Bubble Sort giam dan theo salary
    for (int i = 0; i < devCount - 1; i++) {
        for (int j = 0; j < devCount - i - 1; j++) {
            if (devList[j].salary < devList[j + 1].salary) {
                // Hoan doi 2 phan tu
                Developer temp = devList[j];
                devList[j] = devList[j + 1];
                devList[j + 1] = temp;
            }
        }
    }
    
    // In ket qua sau khi sap xep
    printf("\n--- Developers Sorted by Salary (Descending) ---\n");
    for (int i = 0; i < devCount; i++) {
        printf("%d. ID: %s | Name: %s | Salary: $%.2f\n",
               i + 1, devList[i].devID, devList[i].fullName, devList[i].salary);
    }
}