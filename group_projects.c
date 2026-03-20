#include "group_projects.h"
void groupProjectsByDeveloper(Project projectList[], int projectCount,
                              Developer developerList[], int developerCount) {

    for (int i = 0; i < developerCount; i++) {

        printf("\nDeveloper: %s - %s\n",
               developerList[i].devID,
               developerList[i].fullName);

        printf("Projects:\n");

        int found = 0;

        for (int j = 0; j < projectCount; j++) {

            if (strcmp(projectList[j].devID, developerList[i].devID) == 0) {

                printf("   %s - %s (%d months)\n",
                       projectList[j].projectID,
                       projectList[j].projectName,
                       projectList[j].duration);

                found = 1;
            }
        }

        if (!found) {
            printf("   No projects assigned\n");
        }
    }
}
