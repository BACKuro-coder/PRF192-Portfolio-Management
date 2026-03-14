int inputInt(char *msg) {
    int value;
    printf("%s", msg);
    scanf("%d", &value);
    return value;
}

double inputSalary() {
    double salary;
    do {
        printf("Enter salary (>=1000): ");
        scanf("%lf", &salary);
        if (salary < 1000)
            printf("Invalid salary! Try again.\n");
    } while (salary < 1000);

    return salary;
}