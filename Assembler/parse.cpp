#include <stdio.h>
#include <string>
#include <algorithm>
#include "codeMap.h"


std::string parse(std::string line){
	const char* working = line.c_str();
	std::string parsed_line;

	//first posibility to parse, an A(ddressing) command
	if (working[0] == '@'){
		//copies the working string into a new variable -> removes the '@' character -> converts to int -> checks corect int value -> converts to binary -> build return string 
		char* temp_string = new char[17];
		strncpy(temp_string, working, 16);
		temp_string = temp_string + 1;
		int address_value = atoi(temp_string);

		if (address_value < 0 || address_value > 32767){
			parsed_line = "error1";
			return parsed_line;
		}
		char* address_binary = new char[16];
		_itoa(address_value, address_binary, 2);
		parsed_line = address_binary;

		while (parsed_line.size() < 16){
			parsed_line.insert(0, "0");
		}
		return parsed_line;

	}

	//second posibility to parse, a C(ompute) command
	//this will cover 3 posibilities of C commands: "dest = comp; jump"  ---  "dest = comp" (jump empty) ---  "comp; jump" (dest empty)
	//stores eached parsed command in individual variables to help construct the final return line
	std::string working_string = working;
	std::string dest, comp, jump;

	if (working_string.find('=') != -1 && working_string.find(';') != -1){
		char* temp_string = new char[sizeof(working)+1];
		strcpy(temp_string, working);
		dest = strtok(temp_string, " =");
		comp = strtok(NULL, ";");
		jump = strtok(NULL, "\n");
		
	}
	else if (working_string.find('=') != -1){
		char* temp_string = new char[sizeof(working)+1];
		strcpy(temp_string, working);
		dest = strtok(temp_string, "=");
		comp = strtok(NULL, "\n");
		
	}
	else if (working_string.find(';') != -1){
		char* temp_string = new char[sizeof(working)+1];
		strcpy(temp_string, working);
		comp = strtok(temp_string, ";");
		jump = strtok(NULL, "\n");
		
	}

	//removes all whitespaces
	dest.erase(std::remove_if(dest.begin(), dest.end(), ::isspace), dest.end());
	comp.erase(std::remove_if(comp.begin(), comp.end(), ::isspace), comp.end());
	jump.erase(std::remove_if(jump.begin(), jump.end(), ::isspace), jump.end());

	std::string test1 = code_dest(dest);
	std::string test2 = code_comp(comp);
	std::string test3 = code_jump(jump);
	parsed_line = "111" + code_dest(dest) + code_comp(comp) + code_jump(jump);
	return parsed_line;
}
