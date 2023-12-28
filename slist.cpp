// CS311 Yoshii F23 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Thanh Dat Vu
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ 
  //cout << "Running slist constructor." << endl << endl;
  //usually call the base class constructor construct an objects, and 
  //derived class constructor can add its own logic on top of the base class's object initialization.
}

// positions always start at 1
int slist::search(el_t key)
{
  Node* current_node = this->Front;
  int pos = 1;
  while(current_node != NULL)
  {
    if(current_node->Elem == key)
    {
      return pos;
    }
    current_node = current_node->Next;
    pos ++;
  }
  return 0; //current hit null mean there is no key in the list -> return 0;
}

el_t slist::search2(el_t X)
{ 
  el_t M; 
  Node* current_node = this->Front;
  while(current_node != NULL)
  {
    if(current_node->Elem.getkey() == X.getkey())
    {
      X = current_node->Elem; //assign the found elem to X
      return X;
    }
    current_node = current_node->Next;
  }
  return M; //current hit null mean there is no key in the list -> return 0;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos)
{
  if (pos < 1 || pos > this->Count) //error case
    throw OutOfRange();
  else
  {
    Node *temp;
    moveTo(pos, temp); //move to pos and set temp point to that node
    temp->Elem = element; //update Temp node Elem 
  }
}

bool slist::operator==(const slist& OtherOne)
{
  // if not the same length, return false immediately
  if (this->Count != OtherOne.Count)
    return false;
  // if the same lengths, check each node to see if the elements are the same
  else
  {
    Node *lhs = this->Front;
    Node *rhs = OtherOne.Front;
    for(int i = 1; i <= this->Count; i++)
    {
      if(lhs->Elem == rhs->Elem)
      {
        lhs = lhs->Next;
        rhs = rhs->Next;
      }
      else
        return false; //if two element in the list is not the same -> false
    }
    return true; // after check everything in two lists and i > count -> true
  }
}