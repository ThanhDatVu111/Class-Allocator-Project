#include "elem.h"
#include <fstream>

// blank element
el_t::el_t()
{
  this->key = " ";  
  this->name = " ";
  this->age = -1;  
  this->studentID = 000000000; // 9 digit
}

// initializing constructor to create an el_t object 
el_t::el_t(string key, string name, int age, int studentID)
{
  this->key = key;
  this->name = name;
  this->age = age;
  this->studentID = studentID;
}

// ONLY the key part should be available to the user of this class
string el_t::getkey()
{
  return this->key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(string akey)
{
  this->key = akey;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (this->key == OtherOne.key) 
    return true; 
  else 
    return false;
}

bool el_t::operator!=(el_t OtherOne)
{
  if (this->key != OtherOne.key) 
    return true; 
  else 
    return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{ 
  os << E.key << "," << E.name << "," << E.age << "," << E.studentID << "  ";
  return os;  
}  
