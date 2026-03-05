void showDevelopers() {
    if (developerCount == 0) {
        printf("No developers found.\n");
        return;
    }

    for (int i = 0; i < developerCount; i++) {
        printf("\nID: %s", developerList[i].devID);
        printf("\nName: %s", developerList[i].fullName);
        printf("\nBirth Year: %d", developerList[i].birthYear);
        printf("\nLanguages: %s", developerList[i].languages);
        printf("\nSalary: %.2f\n", developerList[i].salary);
    }
}