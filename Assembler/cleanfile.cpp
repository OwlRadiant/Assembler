#include <string>
#include <algorithm>

void clean_whitespaces(std::string& line){
	if (line == "") return;
	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	return;
}

void clean_comments(std::string& line){
	if (line == "") return;
	if (line.find_first_of("//") != -1){
		line.erase(line.find_first_of("//"), line.size());
	}
	return;
}

void clean_all(std::string& line){
	clean_whitespaces(line);
	clean_comments(line);
	return;
}