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
      else if(user_input == "x" || user_input == "X")
         exit_now = true;
   }
}

