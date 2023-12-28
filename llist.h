#include "elem.h"
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
 protected:
  Node *Front;  // pointer to the front node
  Node *Rear;   // pointer to the rear node
  int  Count;   // counter for the number of nodes
  // untility function to move to a specified node position
  void moveTo(int, Node*&);
 public:
  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range
  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //return true if Front and Rear are both pointing to NULL and Count is 0.  
  bool isEmpty();

  //Display each element of the list starting from Front, enclosed in  [ ] followed by endl.
  //E.g. [ 1 2 3 ]  blanks between elements horizontally (special case: if the list is empty, display [ empty ] ).
  void displayAll();

  //special case: if this is going to be the very first node, must
 	//create a new node and make Front and Rear point to it. Put NewNum in the Elem field of this new node. Count is updated.
  //regular case: add a new node at the front and puts NewNum in the Elem field of this new node. Count is updated. 
  void addFront(el_t);
    
  //special case: if this is going to be the very first node, you must
 	//create a new node and make Front and Rear point to it. Put NewNum in the Elem field of this new node. Count is updated.
  //regular case: add a new node at the rear and puts NewNum in the Elem field of this new node. Count is updated.
  void addRear(el_t);

  //error case: if the List is empty, throw an exception.
  //special case: if this is going to make the list empty, give back the front node element through OldNum 
	//(pass by reference) and also remove the front node. Count is updated.Make sure both Front and Rear both become NULL.
  //regular case: give back the front node element through OldNum (pass by reference) and also remove the front node. Count is updated.
  void deleteFront(el_t&);
  
  //error case: if empty, throw an exception.
  //special case: if this is going to make the list empty, give back the rear node element through OldNum (pass by reference)
  //and also remove the rear node. Count is updated. Make sure both Front and Rear become NULL).
  //regular case: give back the rear node element through OldNum (pass by reference)
  //and also remove the rear node. Count is updated.
  void deleteRear(el_t&);

  //---------------------------------------

  //Error cases: If I is an illegal value (i.e. > Count or < 1) throw an exception.
  //Special cases: this should simply call deleteFront (I = 1) or deleteRear (I == Count) for some cases.
	//Regular case: will delete the Ith node (I starts out at 1).  Count is updated.
  void deleteIth(int, el_t&);  // calls moveTo

  //Error cases: If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.      
  //Special cases: this should simply call addFront (I == 1) or addRear (I == Count+1) for some cases.
  //Regular case:  will add right before the Ith node.  Count is updated.
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 
};
