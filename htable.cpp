// ============================================
// Name: Thanh Dat Vu
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{
  //slist has a constructor that based on llist
  for(int i = 0; i < TSIZE; i ++)
  {
    this->table[i] = slist();
  }
}

htable::~htable()
{
  cout << "Calling htable destructor" << endl;
  // No need to explicitly call llist::~llist() here from slist
}

// a simple hash function that uses % TSIZE simply
int htable::hash(string key)
{
  string shortenedKey = key.substr(0, 3);
  unsigned numKey = 0;
  for (int i = 0; i < 3; i ++)
  {
    numKey += shortenedKey[i] - 'A';
  }
  return numKey % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element)
{
  int slot = hash(element.getkey()); // hash with the key part
  // Note that this means adding the element to a slist in the slot (call addRear)
  this->table[slot].addRear(element);
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(string s_key)
{ 
  int slot = hash(s_key); // hash with skey
  el_t s_element;  // this is the element to look for in slist
  // initialize selement with just the skey (call setkey)
  s_element.setkey(s_key);
  // call slist's search2 with selement which returns the found element 
  // return the found element from here (it could be blank)
  return this->table[slot].search2(s_element); 
}

// finds the element given the key and deletes it from the table.
int htable::deleteIt(string s_key)
{
  int slot = hash(s_key); //hash with skey
  el_t s_element;  // this is the element to look for in slist
  // initialize selement with just the skey
  s_element.setkey(s_key);
  // call slist's search which gives you the location I and then deleteIth
  int locationI = this->table[slot].search(s_element);
  if(locationI != 0)
  {
    this->table[slot].deleteIth(locationI, s_element);
    return slot;
  }
  else
    return 0;
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ 
  string akey,aname;
  int aage, astudentID;
  // model this after HW6 to get data from the file the user specified
  // which elem and slist functions do you call? List them here first. 
  // fill constructor to create an element and add() to add into the list
  while (getline(fin, akey, ','))
  { 
    // fin other parts and create an element
    getline(fin,aname,',');
    fin >> aage;
    fin.ignore();
    fin >> astudentID;
    fin.ignore(); //ignore the rest. 
    el_t new_element(akey, aname, aage, astudentID);
    // call the add function to add the created element to the table
    add(new_element);
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { 
      cout << i << ": " ;   
      // call slist's displayAll
      this->table[i].displayAll();
    }
}

//saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{
  //for each non-empty slot of the table, retrieve the slist to a local variable and fout each removed element.
  for (int i = 0; i < TSIZE; i++)
  {
    if (!table[i].isEmpty())
    {
      // Retrieve the slist in the current slot
      slist retrieveSlist = table[i];
      el_t deletedElem;
      while (!retrieveSlist.isEmpty())
      {
        retrieveSlist.deleteFront(deletedElem);
        fout << deletedElem << endl;
      }
    }
  }
}
