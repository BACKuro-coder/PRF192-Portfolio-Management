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

#endif
