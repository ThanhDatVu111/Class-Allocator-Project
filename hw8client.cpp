//============================================
// Name: Thanh Dat Vu
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>

//=====An explanation of what this App should be used for.======
//This app is used for Quick Information Retrieval:
//Using the key number, we can quickly retrieve the corresponding student information in that specific class.
//This is especially useful when we have a large dataset, and we want to access information 
//about individuals without having to search through the entire list.
int main()
{ 
  //cout an explanation of what this App should be used for. 
  cout << "\n===== An explanation of what this App should be used for ======" << endl;
  cout << "Scenario: Class Selection and Student Allocation" << endl;
  cout << "          Allocate Students to 37 Different Classes based on thier selection."<< endl;
  cout << "          Keys represent classes, first student enroll into the class will be place at the start." << endl;
  cout << "Purpose:  Efficient Class and Student Adjustments." << endl;
  cout << "          Quick Identification of Class." << endl;
  cout << "          Customized Allocation Logic." << endl;
  cout << "          Data-Driven Classroom Organization:" << endl;

  htable HT;
  string fname; // file name - decided to get the file name here in the client in case the way I get them is application dependent

  cout << "\nWhat is the input file? (.txt file): ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in);
  HT.fillTable(fin);
  // make sure some of elements collide. 
  HT.displayTable();
 
  cout << endl;

  // this is the output file - newout.txt
  ofstream fout ("newout.txt", ios::out);  

  int selection;
  do 
  {
    cout << "---- MENU ----" << endl; 
    cout << "1: Add an element" << endl; 
    cout << "2: Find an element" << endl;
    cout << "3: Delete an element" << endl;
    cout << "4: Display the table" << endl;
    cout << "5: Save the table to a file at the end" << endl;    
    cout << "6: Quit" << endl;
    cout << "--------------" << endl; 
    cout << "Enter here: "; cin >> selection;

    string thekey;
    int theage, thestudentID;
    string thename;
    el_t theelement;
    int s;

    switch (selection) 
    {
      case 1: // Add and indicate slot
        cout << "What is the key to add: ";
        cin >> thekey;
        cout << "What is the student name: ";
        cin.ignore();
        getline(cin,thename);
        cout << "What is the student age: ";
        cin >> theage;
        cout << "What is the student ID: ";
        cin >> thestudentID;
        // Create the element with all the info using the 2nd constructor
        theelement = el_t(thekey, thename, theage, thestudentID);
        s = HT.add(theelement);
        cout << "Added the element in slot " << s << endl;
        break;

      case 2: // Find and indicate element
        cout << "What is the key to find? ";
        cin >> thekey;
        theelement =  HT.find(thekey); // find based on thekey
        if (theelement.getkey() != " ")
          cout << "Found this: " << theelement << endl;
        else
          cout << "Key not Found!!!" << endl;
        break;      

      case 3: // Delete and indicate slot
        cout << "What is the key to find and delete? ";
        cin >> thekey;
        s = HT.deleteIt(thekey); // find and delete it based on thekey
        if (s == 0) 
          cout << "Not found!" << endl; 
        else
          cout << "Found it and deleted it from slot: " << s << endl;
        break;      

      case 4: // Display
        cout << "The current contents are: " << endl;
        HT.displayTable();
        break;

      case 5: // Save in the same format as input file
        HT.saveTable(fout);
        cout << "Saved the updated table in newout.txt" << endl;
        break;

      default:
        cout << "Thank you for using the app." << endl;
    }
  }
  while (selection != 6);
  fin.close();
  fout.close();
  return 0;
 }
