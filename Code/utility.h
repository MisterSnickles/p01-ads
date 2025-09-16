#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

struct Personal_record {
	std::string first_name;
	std::string last_name;
	std::string ID;
};

void visit(Personal_record &r);

enum Error_code { duplicate_error, not_present, success, overflow, underflow, range_err, fail };

// returns a new string with all trailing white space chars (" \n\r\t") removed 
std::string rtrim(std::string s);
