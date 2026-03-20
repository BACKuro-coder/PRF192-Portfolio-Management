#include <stdio.h>
#include <stdlib.h>
#include "file_helper.h"

// Luu danh sach Developer ra file nhi phan
int saveDevelopersToFile(const char* filename, Developer* devs, int count) {
    FILE* file = fopen(filename, "wb"); // "wb" cho binary
    if(file == NULL) return 0;
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(devs, sizeof(Developer), count, file);
    
    fclose(file);
    return 1;
}

// Doc danh sach Developer tu file nhi phan
int loadDevelopersFromFile(const char* filename, Developer** devs, int* count) {
    FILE* file = fopen(filename, "rb"); // "rb" cho binary
    // Neu file chua ton tai (lan dau chay) thi bo qua, khong bao loi
    if (file == NULL) return 0;
    
    // Doc so luong Developer
    if (fread(count, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 0;
    }
    
    // Cap phat bo nho cho mang Developer
    *devs = (Developer*)malloc((*count) * sizeof(Developer));
    if (*devs == NULL) {
        fclose(file);
        return 0;
    }
    
    // Doc toan bo Developer tu file
    if (fread(*devs, sizeof(Developer), *count, file) != *count) {
        free(*devs);
        *devs = NULL;
        *count = 0;
        fclose(file);
        return 0;
    }
    
    fclose(file);
    return 1;
}

// Luu danh sach Project ra file nhi phan
int saveProjectsToFile(const char* filename, Project* projs, int count) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return 0;
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(projs, sizeof(Project), count, file);
    
    fclose(file);
    return 1;
}

// Doc danh sach Project tu file nhi phan
int loadProjectsFromFile(const char* filename, Project** projs, int* count) {
    FILE* file = fopen(filename, "rb");
    // Neu file chua ton tai (lan dau chay) thi bo qua
    if (file == NULL) return 0;
    
    // Doc so luong Project
    if (fread(count, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 0;
    }
    
    // Cap phat bo nho cho mang Project
    *projs = (Project*)malloc((*count) * sizeof(Project));
    if (*projs == NULL) {
        fclose(file);
        return 0;
    }
    
    // Doc toan bo Project tu file
    if (fread(*projs, sizeof(Project), *count, file) != *count) {
        free(*projs);
        *projs = NULL;
        *count = 0;
        fclose(file);
        return 0;
    }
    
    fclose(file);
    return 1;
}