void saveDeveloperToFile() {
    FILE *f = fopen("developers.txt", "w");

    for (int i = 0; i < developerCount; i++) {
        fprintf(f,"%s,%s,%d,%s,%.2f\n",
        developerList[i].devID,
        developerList[i].fullName,
        developerList[i].birthYear,
        developerList[i].languages,
        developerList[i].salary);
    }

    fclose(f);
    printf("Saved to file successfully!\n");
}
void loadDeveloperFromFile() {
    FILE *f = fopen("developers.txt", "r");

    if (f == NULL) {
        printf("File not found!\n");
        return;
    }

    Developer d;

    while (fscanf(f,"%[^,],%[^,],%d,%[^,],%lf\n",
        d.devID,
        d.fullName,
        &d.birthYear,
        d.languages,
        &d.salary) == 5) {

        resizeArray();
        developerList[developerCount++] = d;
    }

    fclose(f);
    printf("Data loaded successfully!\n");
}