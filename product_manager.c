#include "product.h"

void initManager(ProductManager *pm, int initialCapacity) {
    pm->capacity = initialCapacity;
    pm->count = 0;
    pm->products = (Product *)malloc(pm->capacity * sizeof(Product));
}

int addProduct(ProductManager *pm, const char *name, double price, int quantity, const char *category) {
    if (pm->count >= pm->capacity) {
        pm->capacity *= 2;
        pm->products = (Product *)realloc(pm->products, pm->capacity * sizeof(Product));
        if (pm->products == NULL) return 0;
    }
    
   
    int newId = pm->count + 1; 
    
    pm->products[pm->count].id = newId;
    strcpy(pm->products[pm->count].name, name);
    pm->products[pm->count].price = price;
    pm->products[pm->count].quantity = quantity;
    strcpy(pm->products[pm->count].category, category);
    pm->products[pm->count].status = 1; 
    
    pm->count++;
    return 1; 
}


int updateProduct(ProductManager *pm, int searchId, double newPrice, int newQuantity) {
    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].id == searchId && pm->products[i].status == 1) {
            pm->products[i].price = newPrice;
            pm->products[i].quantity = newQuantity;
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
    printf("--- Ket qua tim kiem cho '%s' ---\n", keyword);
    for (int i = 0; i < pm->count; i++) {
       
        if (pm->products[i].status == 1 && strstr(pm->products[i].name, keyword) != NULL) {
            printf("ID: %d | Name: %s | Price: $%.2f | Qty: %d\n", 
                   pm->products[i].id, pm->products[i].name, pm->products[i].price, pm->products[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay san pham nao!\n");
}


void sortProduct(ProductManager *pm) {
    for (int i = 0; i < pm->count - 1; i++) {
        for (int j = 0; j < pm->count - i - 1; j++) {
            if (pm->products[j].price > pm->products[j+1].price) {
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
        char name[100];
        double price;
        int quantity;
        char *token = strtok(line, ",");
        if (token != NULL) strcpy(name, token);
        
        token = strtok(NULL, ",");
        if (token != NULL) price = atof(token);
        
        token = strtok(NULL, ",\n");
        if (token != NULL) quantity = atoi(token);
        addProduct(pm, name, price, quantity, "General");
    }
    fclose(file);
    return 1;
}

int saveProductToFile(ProductManager *pm, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) return 0;

    for (int i = 0; i < pm->count; i++) {
        if (pm->products[i].status == 1) {
            fprintf(file, "%s,%.2f,%d\n", 
                    pm->products[i].name, pm->products[i].price, pm->products[i].quantity);
        }
    }
    
    fclose(file);
    return 1;
}
