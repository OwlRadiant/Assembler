#include <stdio.h>
#include <string>


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

		
	}

	//second posibility to parse, a C(ompute) command


	return parsed_line;
}
