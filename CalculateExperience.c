#include "CalculateExperience.h"
void calculateTotalExperience(Project projectList[], int projectCount) {

    char devID[10];
    int totalDuration = 0;

    printf("Enter Developer ID: ");
    scanf("%s", devID);

    for (int i = 0; i < projectCount; i++) {
        if (strcmp(projectList[i].devID, devID) == 0) {
            totalDuration += projectList[i].duration;
        }
    }

    printf("Total project experience: %d months\n", totalDuration);
}
