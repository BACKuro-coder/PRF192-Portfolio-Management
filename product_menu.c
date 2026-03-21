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
        printf("\n--- SOFTWARE PRODUCT MANAGEMENT ---\n");
        printf("1. Add Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Search Product\n");
        printf("5. Sort Products by Name\n");
        printf("6. Show All Products\n");
        printf("0. Back to Main Menu\n");
        printf("-----------------------------------\n");
        
        choice = getValidInt("Enter your choice (0-6): ", 0, 6);
        
        switch (choice) {
            case 1: {
                char name[100], devID[10], version[20], platform[50];
                getString("Enter Product Name (e.g., Portfolio Manager): ", name, 100);
                
                // Nhap va validate Developer ID
                do {
                    getString("Enter Developer ID (DEVxxx): ", devID, 10);
                    if (!isExistingDevID(devID)) {
                        printf("Error: Developer ID '%s' does not exist.\n", devID);
                    } else {
                        break;
                    }
                } while (1);
                
                getString("Enter Version (e.g., 1.0.0): ", version, 20);
                getString("Enter Platform (Web/Mobile/Desktop): ", platform, 50);
                
                if (addProduct(&productMgr, name, devID, version, platform)) {
                    printf("Software product added successfully! (ID: %d)\n", productMgr.count);
                } else {
                    printf("Error: Failed to add product.\n");
                }
                break;
            }
            case 2: {
                int id;
                char newVersion[20], newPlatform[50];
                id = getValidInt("Enter Product ID to update: ", 1, 99999);
                getString("Enter new Version (e.g., 2.0.0): ", newVersion, 20);
                getString("Enter new Platform (Web/Mobile/Desktop): ", newPlatform, 50);
                if (updateProduct(&productMgr, id, newVersion, newPlatform)) {
                    printf("Product updated successfully!\n");
                } else {
                    printf("Error: Product not found or already discontinued.\n");
                }
                break;
            }
            case 3: {
                int id;
                id = getValidInt("Enter Product ID to delete: ", 1, 99999);
                if (deleteProduct(&productMgr, id)) {
                    printf("Product discontinued successfully!\n");
                } else {
                    printf("Error: Product not found or already discontinued.\n");
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
                printf("Products sorted by name (A-Z).\n");
                // Show sorted results
                for (int i = 0; i < productMgr.count; i++) {
                    if (productMgr.products[i].status == 1) {
                        printf("%d. ID: %d | %s | Dev: %s | Ver: %s | %s\n",
                               i + 1, productMgr.products[i].id,
                               productMgr.products[i].name,
                               productMgr.products[i].devID,
                               productMgr.products[i].version,
                               productMgr.products[i].platform);
                    }
                }
                break;
            case 6:
                if (productMgr.count == 0) {
                    printf("No software products found.\n");
                } else {
                    printf("\n--- All Software Products ---\n");
                    for (int i = 0; i < productMgr.count; i++) {
                        if (productMgr.products[i].status == 1) {
                            printf("ID: %d | %s | Dev: %s | Ver: %s | %s\n",
                                   productMgr.products[i].id,
                                   productMgr.products[i].name,
                                   productMgr.products[i].devID,
                                   productMgr.products[i].version,
                                   productMgr.products[i].platform);
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
