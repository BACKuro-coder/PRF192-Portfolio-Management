#include <stdio.h>
#include <string.h>
#include "data_types.h"
#include "console_io.h"
#include "portfolio_manager.h"
#include "product.h"
#include "product_menu.h"

// ================= PRODUCT SUBMENU =================
void productMenu() {
    int choice;
    do {
        printf("\n--- PRODUCT MANAGEMENT ---\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Sort Products by Price\n");
        printf("6. Show All Products\n");
        printf("0. Back to Main Menu\n");
        printf("---------------------------\n");
        
        choice = getValidInt("Enter your choice (0-6): ", 0, 6);
        
        switch (choice) {
            case 1: {
                char name[100], category[50];
                double price;
                int quantity;
                getString("Enter Product Name: ", name, 100);
                price = getValidFloat("Enter Price (min $0.01): ", 0.01f);
                quantity = getValidInt("Enter Quantity (1-99999): ", 1, 99999);
                getString("Enter Category: ", category, 50);
                if (addProduct(&productMgr, name, price, quantity, category)) {
                    printf("Product added successfully! (ID: %d)\n", productMgr.count);
                } else {
                    printf("Error: Failed to add product.\n");
                }
                break;
            }
            case 2: {
                int id;
                double newPrice;
                int newQty;
                id = getValidInt("Enter Product ID to update: ", 1, 99999);
                newPrice = getValidFloat("Enter new Price (min $0.01): ", 0.01f);
                newQty = getValidInt("Enter new Quantity (1-99999): ", 1, 99999);
                if (updateProduct(&productMgr, id, newPrice, newQty)) {
                    printf("Product updated successfully!\n");
                } else {
                    printf("Error: Product not found or already deleted.\n");
                }
                break;
            }
            case 3: {
                int id;
                id = getValidInt("Enter Product ID to delete: ", 1, 99999);
                if (deleteProduct(&productMgr, id)) {
                    printf("Product deleted successfully!\n");
                } else {
                    printf("Error: Product not found or already deleted.\n");
                }
                break;
            }
            case 4: {
                char keyword[100];
                getString("Enter keyword to search: ", keyword, 100);
                searchProduct(&productMgr, keyword);
                break;
            }
            case 5:
                sortProduct(&productMgr);
                printf("Products sorted by price (ascending).\n");
                // Show sorted results
                for (int i = 0; i < productMgr.count; i++) {
                    if (productMgr.products[i].status == 1) {
                        printf("%d. ID: %d | %s | $%.2f | Qty: %d | %s\n",
                               i + 1, productMgr.products[i].id,
                               productMgr.products[i].name,
                               productMgr.products[i].price,
                               productMgr.products[i].quantity,
                               productMgr.products[i].category);
                    }
                }
                break;
            case 6:
                if (productMgr.count == 0) {
                    printf("No products found.\n");
                } else {
                    printf("\n--- All Products ---\n");
                    for (int i = 0; i < productMgr.count; i++) {
                        if (productMgr.products[i].status == 1) {
                            printf("ID: %d | %s | $%.2f | Qty: %d | %s\n",
                                   productMgr.products[i].id,
                                   productMgr.products[i].name,
                                   productMgr.products[i].price,
                                   productMgr.products[i].quantity,
                                   productMgr.products[i].category);
                        }
                    }
                }
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
        }
    } while (choice != 0);
}
