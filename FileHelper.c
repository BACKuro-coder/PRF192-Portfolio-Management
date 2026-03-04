#include <stdio.h>
#include <stblib.h>
#include "FileHelper.h"

int saveDelopersToFile(const char* filename, Developer* devs, int count){
	FILE* file = fopen(filename, "wb"); //use "wb" for binary || "w" for text
	if(file==NULL) return 0;
	
	fwrite(&count, sizeof(int), 1, file);
	fwrite(devs, sizeof(Developer), count, file);
	
	fclose(file);
	return 1;
}

//TODO
//Implement Load with fread()