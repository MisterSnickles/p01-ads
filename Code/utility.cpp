#include "utility.h"
#include <iostream>
#include <iomanip>

using namespace std;

std::string rtrim(std::string str) {
   std::string s = str;
   return s.erase(s.find_last_not_of(" \n\r\t") + 1);   
}

void visit(Personal_record &r){
   cout << left << setw(12) << "Last Name: " << r.last_name << endl;
   cout << left << setw(12) << "First Name: " << r.first_name << endl;
   cout << left << setw(12) << "ID: " << r.ID << endl;
   cout << "--------------------" << endl;
}