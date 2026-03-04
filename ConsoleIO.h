#ifndef CONSOLEIO_H
#define CONSOLEIO_H

void printMenu();
int getValidInt(const char* prompt, int min. int max);
float getValidFloat(const char* prompt, float min);
void getString(const char* prompt, char* buffer, int maxLenght);

#endif