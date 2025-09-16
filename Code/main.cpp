#include "utility.h"
#include "List.h"

using namespace std;

int main(){
   clock_t start, finish;
   double elapsed_time;

   bool exit_now = false;
   List<Personal_record> record_list;

   string user_input;

   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Import List from File" << endl;
      cout << "2. Display List" << endl;
      cout << "3. Search List" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      cin >> user_input;

      if(user_input == "1"){
         string input;
         cout << endl << "Enter Data File Name:" << endl;
         cin >> input;
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            record_list.clear();

            Personal_record input_rec;
            string ID_string;
            while ((insertion_file >> input_rec.last_name) && 
                  (insertion_file >> input_rec.first_name) &&
                  (insertion_file >> ID_string)) {
               input_rec.last_name = rtrim(input_rec.last_name);
               input_rec.first_name = rtrim(input_rec.first_name);
               input_rec.ID = rtrim(ID_string);
               
               // write code to implement Requirement 1
               
               // defining second 'retrival' record variable that with change with iteration of for loop
               Personal_record ret_rec;
               // reset in for loop below to signal if should insert at end of list
               bool record_inserted = false;

               // to iterate through list to compare last names with ith index last name
               for (int i = 0; i < record_list.size(); i++){

                  // to retrive a record variable on ith index and assign it to ret_rec variable
                  record_list.retrieve(i, ret_rec);
                  
                  // string lib compare function returns -1 if first/last name comes before ret_rec alphabetically, 0 if equal, 1 if after
                  int compare_last = input_rec.last_name.compare(ret_rec.last_name);
                  int compare_first = input_rec.first_name.compare(ret_rec.first_name);
                  
                  // start of if/else statements (not nested)
                  // if both first and last names match or ids match
                  if ((input_rec.last_name == ret_rec.last_name && input_rec.first_name == ret_rec.first_name) ||
                     (input_rec.ID == ret_rec.ID)) {
                     cout << "Duplicate record found. Discarding." << endl;
                     record_inserted = true;
                     break;
                  } 

                  // if last name comes before or (last name is the same and first name comes before)
                  else if (compare_last < 0 || (compare_last == 0 && compare_first < 0)) {
                     record_list.insert(i, input_rec);
                     record_inserted = true;
                     break;
                  }
               } 

               // if not inserted, it goes at end
               if (!record_inserted) {
                  record_list.insert(record_list.size(), input_rec);
               } 
            }

         } else
            cout << "Invalid file name." << endl;
		insertion_file.close();
      }
      else if(user_input == "2"){

      

      // write code to implement Requirement 2

      
      
      }
      else if(user_input == "3"){
         string search_first_name, search_last_name, search_ID;
         start = clock();



         // write code to implement Requirement 3





         finish = clock();
         elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
         cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;
      } 
      else if(user_input == "x" || user_input == "X" || user_input == "4"){
         exit_now = true;
      }
   }
}

