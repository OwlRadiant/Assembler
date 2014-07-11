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
#include "symboltable.h"
#include "cleanfile.h"
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

	//after succesful opening of file initializes codemap that will translate assembly to machine code; also initialize symbol table to store labels/symbols
	init_codemap();
	init_symbol_table();

	//opens output file and names it accordingly
	ofstream outputfile(getFileName(argv[1]) + ".hack");

	//get line from inputfile
	//parse(line)
	//write line to outputfile
	string line;
	int line_count = -1;
	int label_count = 0;
	stringstream ss;

	//The first pass of the file will parse only the label symbols to generate their memory value, 
	//then store the file in a temporary stringstream and REMOVE all lines with labels
	//This allows the assembler to use calls to labels that have not been defined yet in the .asm file
	while (getline(inputfile, line)){
		
		//cleans the line of any whitespaces or comments
		clean_all(line);
		if (line == "") continue;
		
		// line_count was above the comment deletion part and would increment after every comment line, which was wrong for our final code
		line_count++;

		//checks label definition
		if (line.find_first_of("(") == 0){
			if (line.find_last_of(")") == line.size() - 1){
				parse_label(line, line_count, label_count);
				label_count++;
				continue;
			}
			else{
				cout << "Error at line " << line_count << endl;
				return -3;
			}
		}
		ss << line << endl;
	}


	//This is the second pass of the file, generating all the code after the first pass has alocated memory for and removed all the labels
	while (getline(ss, line)){
				
		string parsed_line = parse(line);
		outputfile << parsed_line << endl;

	}		
	inputfile.close();
	outputfile.close();
	//getchar();
	return 0;
}

