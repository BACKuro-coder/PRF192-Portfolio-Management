void resizeArray() {
    if (developerCount >= capacity) {
        capacity = capacity == 0 ? 5 : capacity * 2;
        developerList = realloc(developerList, capacity * sizeof(Developer));

        if (developerList == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
}