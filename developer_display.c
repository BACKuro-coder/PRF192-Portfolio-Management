#include <stdio.h>
#include <string.h>
#include "data_types.h"
#include "portfolio_manager.h"
#include "developer_display.h"

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

// ================= HAM SHOW ALL DEVELOPERS =================
void showAllDevelopers() {
    if (devCount == 0) {
        printf("The developer list is empty.\n");
        return;
    }
    printf("\n--- All Developers ---\n");
    for (int i = 0; i < devCount; i++) {
        printf("%d. ID: %s | Name: %s | Year: %d | Lang: %s | Salary: $%.2f | Projects: %d\n",
               i + 1, devList[i].devID, devList[i].fullName, devList[i].birthYear,
               devList[i].languages, devList[i].salary, devList[i].projectCount);
    }
}
