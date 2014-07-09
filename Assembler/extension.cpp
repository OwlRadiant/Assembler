#include <string>

std::string getFileExtension(char *filename){
	std::string extension;
	char* temp = strtok(filename, ".");
	//use temp to check for file end before comitting result of strtok to extension

	while (temp != NULL){

		temp = strtok(NULL, ".");
		if (temp != NULL) extension = temp;
	}

	return extension;
}