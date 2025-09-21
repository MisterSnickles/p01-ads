#include "utility.h"
#include "List.h"
#include <iomanip>
#include <cctype> // header for to_lower() function

using namespace std;

string toLower(const string &);

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

            Personal_record input_record;
            string ID_string;
            while ((insertion_file >> input_record.last_name) && 
                  (insertion_file >> input_record.first_name) &&
                  (insertion_file >> ID_string)) {
               input_record.last_name = rtrim(input_record.last_name);
               input_record.first_name = rtrim(input_record.first_name);
               input_record.ID = rtrim(ID_string);
               
            //START. write code to implement Requirement 1
               
               // defining second 'retrival' record variable that with change with iteration of for loop
               Personal_record retrieve_record;
               // reset in for loop below to signal if should insert at end of list
               bool record_inserted = false;

               // to iterate through list to compare last names with ith index last name
               for (int i = 0; i < record_list.size(); i++){

                  // to retrive a record variable on ith index and assign it to retrieve_record variable
                  record_list.retrieve(i, retrieve_record);
                  
                  // string lib compare function returns -1 if first/last name comes before retrieve_record alphabetically, 0 if equal, 1 if after
                  int compare_last = input_record.last_name.compare(retrieve_record.last_name);
                  int compare_first = input_record.first_name.compare(retrieve_record.first_name);
                  
                  // start of if/else statements (not nested)
                  // if both first and last names match or ids match
                  if ((input_record.last_name == retrieve_record.last_name && input_record.first_name == retrieve_record.first_name) ||
                     (input_record.ID == retrieve_record.ID)) {
                     cout << "Duplicate record found. Discarding." << endl;
                     record_inserted = true;
                     break;
                  } 

                  // if last name comes before or (last name is the same and first name comes before)
                  else if (compare_last < 0 || (compare_last == 0 && compare_first < 0)) {
                     record_list.insert(i, input_record);
                     record_inserted = true;
                     break;
                  }
            // END. write code to implement Requirement 1

               } 

               // if not inserted, it goes at end
               if (!record_inserted) {
                  record_list.insert(record_list.size(), input_record);
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
      //START. write code to implement Requirement 3
         string search_first_name, search_last_name, search_ID, again, search_type;
         bool found = false;
         Personal_record retrieve_record;
         
         // a list to hold any matching records using fuzzy search logic
         List<Personal_record> matching_records;              
         const int fuzzy = 2;

         if (record_list.empty()){cout << "Record is empty! Enter a file to continue." << endl;}
         else{
            do{
               search_ID = -1;
               found = false;
               cout << "Do you want to search by ID or by First and Last names?" << endl;
               cout << "Enter \"id\" or \"fl\" : ";
               cin >> search_type;
               
               //Input validation. Make sure user enters the proper string
               while(   search_type != "ID" && search_type != "id" && search_type != "FL" && search_type != "fl") {
                           cout << "Invalid input!. " << endl;
                           cout << "Enter \"id\" or \"fl\" : ";
                           cin >> search_type;
                        }

               //Search based on ID number.
               if (search_type == "ID" || search_type == "id"){
                  cout << "Enter ID you wish to search:  ";
                  cin >> search_ID;

                  for (int i=0; i<record_list.size(); ++i){
                     start = clock();
                     if((record_list.retrieve(i, retrieve_record)) == success && retrieve_record.ID == search_ID){
                           found = true; 
                           matching_records.insert(0, retrieve_record);
                           break;
                     } 
                  }
               }


               //Search based on First and Last name.
               if (search_type == "FL" || search_type == "fl"){
                        string user_search;
                        cout << "Enter First, then Space, then Last. I.E. \"First Last\": ";
                        getline(cin >> ws, user_search);
                        user_search = toLower(user_search);
                        
                        start = clock();

                        // find space within user input if searching via full name
                        size_t space_pos = user_search.find(' ');

                        // if space was found
                        if (space_pos != string::npos) {

                           // assign first and last name to string before and after space character
                           search_first_name = user_search.substr(0, space_pos);
                           search_last_name = user_search.substr(space_pos + 1);

                           // iterate through each record object in list
                           for (int i = 0; i < record_list.size(); ++i) {
                              record_list.retrieve(i, retrieve_record);
                              
                              // convert first and last name into lower case for easier search
                              string last_name = toLower(retrieve_record.last_name);
                              string first_name = toLower(retrieve_record.first_name);
                              
                              // if retrived first/last name match search first/last name
                              if ((last_name.find(search_last_name) == 0) && (first_name.find(search_first_name) == 0) ) {
                                 found = true;
                                 matching_records.insert(0, retrieve_record);
                                 
                              }
                           }
                        } 
               }
               

               // prints out the record if it is found in the list. otherwise, it prints not found
               if(found){
                  cout << endl << "Record Found" << endl;
                  matching_records.traverse(visit);
                  matching_records.clear();
               } else{ cout << "Record not found" << endl;}


               //stop the clock and print out the time it took to find the record
               finish = clock();
               elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
               cout << endl << "Time: " << elapsed_time << " seconds" << endl << endl;


               //ask the user if they want to find anothe record
               cout << "Do you want to search again? (y/n):  " ;
               cin >> again;
               cout << endl;
            } while( again == "y" || again == "Y" || again == "Yes" || again == "yes" || again == "sure" || again == "yeah" || again == "yea" || again == "why-not" || again == "hell-yeah!");
      //END. write code to implement Requirement 3
         
         }
      } 
      else if(user_input == "x" || user_input == "X" || user_input == "4"){
         exit_now = true;
      }
   }
}


string toLower(const string &original_str) {
   string result = original_str;
   for (char &c: result) {
      c = tolower(c);
   }
   return result;
}