#include <string>
#include <unordered_map>
#include "codeMap.h"

std::unordered_map<std::string, std::string> code_map_dest;
std::unordered_map<std::string, std::string> code_map_comp;
std::unordered_map<std::string, std::string> code_map_jump;

std::string code_dest(std::string mnemonic){
	return code_map_dest[mnemonic];
}

std::string code_comp(std::string mnemonic){
	return code_map_comp[mnemonic];
}

std::string code_jump(std::string mnemonic){
	return code_map_jump[mnemonic];
}



void init_codemap(){
	code_map_dest[""] =     "000";
	code_map_dest["M"]    = "001";
	code_map_dest["D"]    = "010";
	code_map_dest["MD"]   = "011";
	code_map_dest["A"]    = "100";
	code_map_dest["AM"]   = "101";
	code_map_dest["AD"]   = "110";
	code_map_dest["AMD"]  = "111";


	code_map_comp["0"]   = "0101010";
	code_map_comp["1"]   = "0111111";
	code_map_comp["-1"]  = "0111010";
	code_map_comp["D"]   = "0001100";
	code_map_comp["A"]   = "0110000";
	code_map_comp["!D"]  = "0001101";
	code_map_comp["!A"]  = "0110001";
	code_map_comp["-D"]  = "0001111";
	code_map_comp["-A"]  = "0110011";
	code_map_comp["D+1"] = "0011111";
	code_map_comp["1+D"] = "0011111";
	code_map_comp["A+1"] = "0110111";
	code_map_comp["1+A"] = "0110111";
	code_map_comp["D-1"] = "0001110";
	code_map_comp["A-1"] = "0110010";
	code_map_comp["D+A"] = "0000010";
	code_map_comp["A+D"] = "0000010";
	code_map_comp["D-A"] = "0010011";
	code_map_comp["A-D"] = "0000111";
	code_map_comp["D&A"] = "0000000";
	code_map_comp["A&D"] = "0000000";
	code_map_comp["D|A"] = "0010101";
	code_map_comp["A|D"] = "0010101";

	code_map_comp["M"]   = "1110000";
	code_map_comp["!M"]  = "1110001";
	code_map_comp["-M"]  = "1110011";
	code_map_comp["M+1"] = "1110111";
	code_map_comp["1+M"] = "1110111";
	code_map_comp["M-1"] = "1110010";
	code_map_comp["D+M"] = "1000010";
	code_map_comp["M+D"] = "1000010";
	code_map_comp["D-M"] = "1010011";
	code_map_comp["M-D"] = "1000111";
	code_map_comp["D&M"] = "1000000";
	code_map_comp["M&D"] = "1000000";
	code_map_comp["D|M"] = "1010101";
	code_map_comp["M|D"] = "1010101";
	

	code_map_jump[""]    = "000";
	code_map_jump["JGT"] = "001";
	code_map_jump["JEQ"] = "010";
	code_map_jump["JGE"] = "011";
	code_map_jump["JLT"] = "100";
	code_map_jump["JNE"] = "101";
	code_map_jump["JLE"] = "110";
	code_map_jump["JMP"] = "111";

}