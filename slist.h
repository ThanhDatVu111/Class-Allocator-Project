//=================================================
// Name: Thanh Dat Vu
// File: slist.h header file
//=================================================

#include "llist.h" // for includes
class slist : public llist
{
  public:
  slist();   // constructor. cout "in slist constructor".
             // Make it do nothing else.
             // Experiment and see what happens.
             // Taking this out completely would not work.
             // But note that there is no destructor.
             // PLEASE DO NOT delete the couts in slist and llist
             // constructors and destructors for HW6!!!!!

  // search through the list to see if any node contains the key.
  // If so, return its position (>=1). Otherwise, return 0.
  int search(el_t);
  el_t search2(el_t);

  // go to the Ith node (if I is between 1 and Count) and replace the element there with the new element. 
  // If I was an illegal value, throw OutOfRange 
  void replace(el_t,  int);
    
  // checks to see of the two lists look the same
  bool operator==(const slist&);
};
