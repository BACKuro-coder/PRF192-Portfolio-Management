#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_types.h"
#include "console_io.h"
#include "portfolio_manager.h"

// Cấp phát biến toàn cục
Developer* devList = NULL;
int devCount = 0;
Project* projectList = NULL;
int projectCount = 0;

void initSystem() {
    
}

void freeSystem() {
    if (devList != NULL) free(devList);
    if (projectList != NULL) free(projectList);
}

// ================= CÁC HÀM VALIDATE =================
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

// ================= HÀM ADD DEVELOPER =================
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

// ================= CÁC HÀM SEARCH =================
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

// ================= HÀM UPDATE SALARY =================
void updateDeveloperSalary() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }

    char searchID[10];
    getString("\nEnter Developer ID to update salary (e.g., DEV001): ", searchID, 10);

    for (int i = 0; i < devCount; i++) {
        // Tìm thấy Developer khớp ID
        if (strcmp(devList[i].devID, searchID) == 0) {
            printf("Found Developer: %s | Current Salary: $%.2f\n", devList[i].fullName, devList[i].salary);
            
            // Gọi hàm bắt nhập lại nếu lương < 1000
            devList[i].salary = getValidFloat("Enter new Monthly Salary (min $1000): ", 1000.0f);
            
            printf("Salary for %s updated successfully to $%.2f!\n", devList[i].fullName, devList[i].salary);
            return; // Cập nhật xong thì thoát hàm
        }
    }
    
    // Nếu chạy hết vòng lặp mà không return nghĩa là không tìm thấy
    printf("Error: Developer with ID '%s' not found.\n", searchID);
}

// ================= HÀM REMOVE DEVELOPER =================
void removeDeveloper() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }

    char searchID[10];
    getString("\nEnter Developer ID to remove: ", searchID, 10);

    int devIndex = -1;
    // 1. Tìm vị trí (index) của Developer trong mảng
    for (int i = 0; i < devCount; i++) {
        if (strcmp(devList[i].devID, searchID) == 0) {
            devIndex = i;
            break;
        }
    }

    // Nếu không tìm thấy
    if (devIndex == -1) {
        printf("Error: Developer with ID '%s' not found.\n", searchID);
        return;
    }

    // 2. Kiểm tra xem Developer có đang vướng Project nào không (Yêu cầu bắt buộc)
    // Duyệt qua mảng projectList của nhóm để tìm
    for (int i = 0; i < projectCount; i++) {
        if (strcmp(projectList[i].devID, searchID) == 0) {
            printf("Error: Cannot remove %s. They are actively assigned to project '%s'.\n", 
                   devList[devIndex].fullName, projectList[i].projectID);
            return; // Đang có project thì CẤM xóa, dừng hàm ngay
        }
    }

    // 3. Tiến hành xóa (Dịch chuyển các phần tử phía sau lên trước 1 bậc)
    printf("Removing developer: %s...\n", devList[devIndex].fullName);
    for (int i = devIndex; i < devCount - 1; i++) {
        devList[i] = devList[i + 1];
    }
    devCount--; // Giảm số lượng đi 1
    
    // 4. Cắt giảm bộ nhớ (realloc) để tối ưu RAM
    if (devCount > 0) {
        Developer* temp = realloc(devList, devCount * sizeof(Developer));
        if (temp != NULL) devList = temp;
    } else {
        free(devList);
        devList = NULL;
    }

    printf("Developer removed successfully.\n");
}

void assignProject() {}
void sortDevelopersBySalary() {}