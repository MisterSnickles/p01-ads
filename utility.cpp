#include "utility.h"

std::string rtrim(std::string str) {
   std::string s = str;
   return s.erase(s.find_last_not_of(" \n\r\t") + 1);   
}