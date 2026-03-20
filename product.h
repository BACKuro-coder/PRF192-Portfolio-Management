#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    double price;
    int quantity;
    char category[50];
    int status;
} Product;

typedef struct {
    Product *products;
    int count;
    int capacity;
} ProductManager;

// Function prototypes
void initManager(ProductManager *pm, int initialCapacity);
int addProduct(ProductManager *pm, const char *name, double price, int quantity, const char *category);
int updateProduct(ProductManager *pm, int searchId, double newPrice, int newQuantity);
int deleteProduct(ProductManager *pm, int searchId);
void searchProduct(ProductManager *pm, const char *keyword);
void sortProduct(ProductManager *pm);
int loadProductFromFile(ProductManager *pm, const char *filename);
int saveProductToFile(ProductManager *pm, const char *filename);

#endif
