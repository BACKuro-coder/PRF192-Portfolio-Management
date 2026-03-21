#include "product.h"

void initManager(ProductManager *pm, int initialCapacity) {
    pm->capacity = initialCapacity;
    pm->count = 0;
    pm->products = (Product *)malloc(pm->capacity * sizeof(Product));
}

int addProduct(ProductManager *pm, const char *name, const char *devID, const char *version, const char *platform) {
    if (pm->count >= pm->capacity) {
        pm->capacity *= 2;
        pm->products = (Product *)realloc(pm->products, pm->capacity * sizeof(Product));
        if (pm->products == NULL) return 0;
    }
    
    int newId = pm->count + 1; 
    
    pm->products[pm->count].id = newId;
    strcpy(pm->products[pm->count].name, name);
    strcpy(pm->products[pm->count].devID, devID);
    strcpy(pm->products[pm->count].version, version);
    strcpy(pm->products[pm->count].platform, platform);
    pm->products[pm->count].status = 1; 
    
    pm->count++;
    return 1; 
}

int updateProduct(ProductManager *pm, int searchId, const char *newVersion, const char *newPlatform) {
    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].id == searchId && pm->products[i].status == 1) {
            strcpy(pm->products[i].version, newVersion);
            strcpy(pm->products[i].platform, newPlatform);
            return 1;
        }
    }
    return 0;
}

int deleteProduct(ProductManager *pm, int searchId) {
    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].id == searchId && pm->products[i].status == 1) {
            pm->products[i].status = 0; 
            return 1;
        }
    }
    return 0;
}

void searchProduct(ProductManager *pm, const char *keyword) {
    int found = 0;
    printf("--- Search results for '%s' ---\n", keyword);
    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].status == 1 && strstr(pm->products[i].name, keyword) != NULL) {
            printf("ID: %d | Name: %s | Dev: %s | Ver: %s | Platform: %s\n", 
                   pm->products[i].id, pm->products[i].name, 
                   pm->products[i].devID, pm->products[i].version,
                   pm->products[i].platform);
            found = 1;
        }
    }
    if (!found) printf("No software product found!\n");
}

// Sort by name (alphabetical ascending)
void sortProduct(ProductManager *pm) {
    for (int i = 0; i < pm->count - 1; i++) {
        for (int j = 0; j < pm->count - i - 1; j++) {
            if (strcmp(pm->products[j].name, pm->products[j+1].name) > 0) {
                Product temp = pm->products[j];
                pm->products[j] = pm->products[j+1];
                pm->products[j+1] = temp;
            }
        }
    }
}

int loadProductFromFile(ProductManager *pm, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char name[100], devID[10], version[20], platform[50];
        
        char *token = strtok(line, ",");
        if (token != NULL) strcpy(name, token);
        
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(devID, token);
        
        token = strtok(NULL, ",");
        if (token != NULL) strcpy(version, token);
        
        token = strtok(NULL, ",\n");
        if (token != NULL) strcpy(platform, token);
        
        addProduct(pm, name, devID, version, platform);
    }
    fclose(file);
    return 1;
}

int saveProductToFile(ProductManager *pm, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) return 0;

    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].status == 1) {
            fprintf(file, "%s,%s,%s,%s\n", 
                    pm->products[i].name, pm->products[i].devID,
                    pm->products[i].version, pm->products[i].platform);
        }
    }
    
    fclose(file);
    return 1;
}
