#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "parse.h"
#include "extension.h"
#include "codeMap.h"
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	ifstream inputfile(argv[1]);

	if (argc != 2) return 1;
	

	//attempts to open the file; if file doesn't exist or doesn't have the .asm extension terminate program
	string extension = getFileExtension(argv[1]);
	if (!(inputfile.is_open()) || extension != "asm"){
		cout << "Input an .asm file to convert to a .hack file." << endl;
		return -1;
	}

	//after succesful opening of file initializes codemap that will translate assembly to machine code
	init_codemap();

	//opens output file and names it accordingly
	ofstream outputfile(getFileName(argv[1]) + ".hack");

	//get line from inputfile
	//parse(line)
	//write line to outputfile
	string line;
	int line_count = 0;
	while (getline(inputfile, line)){
		line_count++;

		//remove all whitespaces from the instruction
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

		if (line.find_first_of("//") == 0) continue;
		

		string parsed_line = parse(line);
		outputfile << parsed_line << endl;

	}

	
	
	inputfile.close();
	outputfile.close();
	//getchar();
	return 0;
}

