#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;              // Ma Product, tu dong tang (1, 2, 3...)
    char name[100];      // Ten phan mem (VD: "Portfolio Manager")
    char devID[10];      // Developer phu trach (VD: "DEV001")
    char version[20];    // Phien ban (VD: "1.0.0")
    char platform[50];   // Nen tang (VD: "Web", "Mobile", "Desktop")
    int status;          // 1 = Active, 0 = Discontinued
} Product;

typedef struct {
    Product *products;
    int count;
    int capacity;
} ProductManager;

// Function prototypes
void initManager(ProductManager *pm, int initialCapacity);
int addProduct(ProductManager *pm, const char *name, const char *devID, const char *version, const char *platform);
int updateProduct(ProductManager *pm, int searchId, const char *newVersion, const char *newPlatform);
int deleteProduct(ProductManager *pm, int searchId);
void searchProduct(ProductManager *pm, const char *keyword);
void sortProduct(ProductManager *pm);
int loadProductFromFile(ProductManager *pm, const char *filename);
int saveProductToFile(ProductManager *pm, const char *filename);

#endif
