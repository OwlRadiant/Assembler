#ifndef CLEANFILE_H
#define CLEANFILE_H
#include <string>

//Cleans the file of any whitespaces
void clean_whitespaces(std::string& line);

//Cleans the file of any comments
void clean_comments(std::string& line);

//Performs all of the above
void clean_all(std::string& line);

#endif