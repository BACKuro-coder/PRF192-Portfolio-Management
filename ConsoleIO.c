#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ConsoleIO.h"

void printMenu() {
    printf("\n==== DEVELOPER & PROJECT PORTFOLIO MANAGEMENT ====\n");
    printf("1. Add a new Developer\n");
    printf("2. Search Developer\n");
    printf("3. Assign Project to Developer\n");
    printf("4. Sort Developers by Salary\n");
    printf("5. Save and Exit\n");
    printf("==================================================\n");
}

void getString(const char* prompt, char* buffer, int maxLength) {
    printf("%s", prompt);
    fflush(stdin);
    fgets(buffer, maxLength, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // xoa ky tu newline
}

// Hàm ép người dùng nhập số nguyên hợp lệ trong khoảng [min, max]
int getValidInt(const char* prompt, int min, int max) {
    int value;
    int check;
    while (1) {
        printf("%s", prompt);
        check = scanf("%d", &value);
        fflush(stdin); // Xóa bộ đệm bàn phím để tránh trôi lệnh nếu nhập sai thành chữ

        if (check == 1 && value >= min && value <= max) {
            return value; // Nhập đúng số nguyên và nằm trong khoảng cho phép
        }
        printf("Error: Invalid input. Please enter an integer between %d and %d.\n", min, max);
    }
}

// Hàm ép người dùng nhập số thực hợp lệ (VD: Lương tối thiểu 1000)
float getValidFloat(const char* prompt, float min) {
    float value;
    int check;
    while (1) {
        printf("%s", prompt);
        check = scanf("%f", &value);
        fflush(stdin); // Xóa bộ đệm bàn phím

        if (check == 1 && value >= min) {
            return value; // Nhập đúng số thực và lớn hơn hoặc bằng min
        }
        printf("Error: Invalid input. Please enter a number >= %.2f.\n", min);
    }
}