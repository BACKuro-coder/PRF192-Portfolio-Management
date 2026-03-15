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
}
