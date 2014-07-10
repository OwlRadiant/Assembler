#ifndef CODEMAP_H
#define CODEMAP_H
#include <string>
#include <unordered_map>

//extern std::unordered_map<std::string, std::string> code_map_dest;
//extern std::unordered_map<std::string, std::string> code_map_comp;
//extern std::unordered_map<std::string, std::string> code_map_jump;

//Return the instruction code from the codemap
std::string code_dest(std::string);
std::string code_comp(std::string);
std::string code_jump(std::string);

//initializez the codemap with all the needed pairings of assembly code -> machine code
void init_codemap();

#endif