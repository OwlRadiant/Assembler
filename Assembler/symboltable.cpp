#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> symbol_table;
int variable_address = 16;

//adresa data la label = linia curenta la label - numarul labelulilor PANA la labelul curent
void parse_label(std::string line, int line_count, int label_count){
	char* temp_cstring = new char[50];
	sscanf(line.c_str(), "(%[^)]", temp_cstring);
	std::string temp_string = temp_cstring;
	symbol_table[temp_string] = line_count - label_count;
	delete[] temp_cstring;
}


//returns address value associated with a symbol; 
//if no address is returned, allocate new memory address and associate it with the element
int get_symbol(std::string symbol){
	if (symbol_table.find(symbol) != symbol_table.end()){
		return symbol_table[symbol];
	}
	else{
		symbol_table[symbol] = variable_address;
		variable_address++;
		return symbol_table[symbol];
	}	
}

void init_symbol_table(){
	symbol_table["SP"]     = 0;
	symbol_table["LCL"]    = 1;
	symbol_table["ARG"]    = 2;
	symbol_table["THIS"]   = 3;
	symbol_table["THAT"]   = 4;
	symbol_table["R0"]     = 0;
	symbol_table["R1"]     = 1;
	symbol_table["R2"]     = 2;
	symbol_table["R3"]     = 3;
	symbol_table["R4"]     = 4;
	symbol_table["R5"]     = 5;
	symbol_table["R6"]     = 6;
	symbol_table["R7"]     = 7;
	symbol_table["R8"]     = 8;
	symbol_table["R9"]     = 9;
	symbol_table["R10"]    = 10;
	symbol_table["R11"]    = 11;
	symbol_table["R12"]    = 12;
	symbol_table["R13"]    = 13;
	symbol_table["R14"]    = 14;
	symbol_table["R15"]    = 15;
	symbol_table["SCREEN"] = 16384;
	symbol_table["KBD"]    = 24576;
	
}