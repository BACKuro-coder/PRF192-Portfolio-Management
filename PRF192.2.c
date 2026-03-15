int assignProjectToDeveloper(Project projectList[], int *projectCount,
                             Developer developerList[], int developerCount) {

    Project p;
    int found = 0;

    printf("Enter Project ID: ");
    scanf("%s", p.projectID);

    printf("Enter Developer ID: ");
    scanf("%s", p.devID);

    // check developer exist
    for (int i = 0; i < developerCount; i++) {
        if (strcmp(developerList[i].devID, p.devID) == 0) {
            found = 1;
            developerList[i].projectCount++;
            break;
        }
    }

    if (!found) {
        printf("Developer not found!\n");
        return 0;
    }

    printf("Enter Project Name: ");
    getchar();
    fgets(p.projectName, sizeof(p.projectName), stdin);

    printf("Enter Duration (months): ");
    scanf("%d", &p.duration);

    printf("Enter Start Date: ");
    scanf("%s", p.startDate);

    printf("Enter Status (1: Active, 0: Completed): ");
    scanf("%d", &p.status);

    projectList[*projectCount] = p;
    (*projectCount)++;

    printf("Project assigned successfully!\n");

    return 1;
}
