#include <stdio.h>
#include <stdlib.h>
#include "file_helper.h"

int saveDevelopersToFile(const char* filename, Developer* devs, int count) {
    FILE* file = fopen(filename, "wb"); // "wb" cho binary, "w" cho text
    if(file == NULL) return 0;
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(devs, sizeof(Developer), count, file);
    
    fclose(file);
    return 1;
}
//TODO
//Implement Load with fread()