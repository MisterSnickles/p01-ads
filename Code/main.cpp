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
               
            //START. write code to implement Requirement 1
               
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
            // END. write code to implement Requirement 1

               } 

               // if not inserted, it goes at end
               if (!record_inserted) {
                  record_list.insert(record_list.size(), input_rec);
               } 
         
            }

         } else
            cout << "Invalid file name." << endl;
		insertion_file.close();
      
      cout << "Added " << record_list.size() << " entries" << endl;
      }
      else if(user_input == "2"){

      // START. write code to implement Requirement 2
         if (record_list.empty()){
            cout << "Record is empty! Enter a file to continue." << endl;
         }else{
            cout << "----Display Record----" << endl;
            record_list.traverse(visit);
            cout << "Number of records: " << record_list.size() << endl;
         }
      // END. write code to implement Requirement 2

      }  
      else if(user_input == "3"){
         string search_first_name, search_last_name, search_ID;
         

      //START. write code to implement Requirement 3
         bool found = false;
         string again;
         string search_type;

         if (record_list.empty()){
            cout << "Record is empty! Enter a file to continue." << endl;
         }else{
            do{
               
               cout << "Do you want to search by ID or by First and Last names?" << endl;
               cout << "Enter \"ID\" or \"FL\" : ";
               cin >> search_type;
               
               //Input validation. Make sure user enters the proper string
               while(   search_type != "ID" &&
                        search_type != "id" &&
                        search_type != "FL" &&
                        search_type != "fl")
                        {
                           cout << "Invalid input!. " << endl;
                           cout << "Enter \"ID\" or \"FL\" : ";
                           cin >> search_type;
                        }
               if (search_type == "ID" || search_type == "id"){
                  
               }
               
               
               
               start = clock();



               if(!found){

                  //search record here

                  cout << "Entry Found" << endl;

               }else{
                  cout << "Record Not Found" << endl;
               }

     
               
               finish = clock();
               elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
               cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;

               cout << "Do you want to search again? (y/n):  " ;
               cin >> again;
               
            } while( again == "y" || 
                     again == "Y" || 
                     again == "Yes" || 
                     again == "yes" || 
                     again == "sure" ||
                     again == "yeah" ||
                     again == "yea" ||
                     again == "why-not" || 
                     again == "hell-yeah!"   // okay, im getting carried away :)
                  );
        
      //END. write code to implement Requirement 3


         }
      } 
      else if(user_input == "x" || user_input == "X" || user_input == "4"){
         exit_now = true;
      }
   }
}

