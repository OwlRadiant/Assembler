#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "parse.h"
using namespace std;

char* getFileExtension(char *filename);

int main(int argc, char** argv){
	FILE* input;
	FILE* output;

	if (argc != 2) return 1;

	//attempts to open the file; if file doesn't exist or doesn't have the .asm extension terminate program
	input = fopen(argv[1], "r");
	char* extension = getFileExtension(argv[1]);
	if (input == NULL || extension == NULL){
		cout << "Input an .asm file to convert to a .hack file.";
		return -1;
	}
	if (strcmp(extension, "asm")){
		cout << "Input an .asm file to convert to a .hack file.";
		return -2;
	}
	char* filename = strtok(argv[1], ".");
	char* outfile = new char[strlen(argv[1]) + strlen(".hack") + 1];
	strcpy(outfile, filename);
	strcat(outfile, ".hack");
	output = fopen(outfile, "a");


	char line[30];

	


	

	

	fclose(input);
	fclose(output);
	fclose(output);
	delete[] outfile;
	return 0;
}

char* getFileExtension(char *filename){
	char* extension = NULL;
	char* temp = strtok(filename, ".");
	//use temp to check for file end before comitting result of strtok to extension

	while (temp != NULL){
		
		temp = strtok(NULL, ".");
		if (temp != NULL) extension = temp;
	}

	return extension;
}