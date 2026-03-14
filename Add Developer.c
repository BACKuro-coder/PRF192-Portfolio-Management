void addDeveloper() {
    resizeArray();

    Developer d;

    printf("Enter Developer ID: ");
    scanf("%s", d.devID);

    printf("Enter Full Name: ");
    getchar();
    fgets(d.fullName, 50, stdin);
    d.fullName[strcspn(d.fullName,"\n")] = 0;

    d.birthYear = inputInt("Enter Birth Year: ");

    printf("Enter Languages: ");
    fgets(d.languages, 50, stdin);
    d.languages[strcspn(d.languages,"\n")] = 0;

    d.salary = inputSalary();

    d.projectCount = 0;

    developerList[developerCount++] = d;

    printf("Developer added successfully!\n");
}