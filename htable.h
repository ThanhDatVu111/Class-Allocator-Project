// CS311 Yoshii - DO NOT CHANGE!!
// This hash table has the slist in each slot
// This hash table knows nothing about elem except the key part
// This way it is easy to change other parts of el_t later.
//=============================================================
#include "slist.h"
const int TSIZE = 37;  // prime number 
class htable
{
  private:
    slist table[TSIZE];   // each node is a key, name, age, driver licence
    int hash(string);   // utility hash function
  public:
    htable();
    ~htable();
    // fills the table by reading data from the istream
    void fillTable(istream&);
    // adds the element and returns the slot number
    int add(el_t);
    // finds the element based on the key and returns it
    el_t find(string);
    // deletes the element based on the key and returns the slot number
    int deleteIt(string);  
    // displays the table including slot numbers
    void displayTable();
    // saves into a file in the same format as the input file
    void saveTable(ostream&); 
};
