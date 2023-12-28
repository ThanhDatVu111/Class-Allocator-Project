//====================================================
//Name: Thanh Dat Vu
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ 
  //cout << "Calling the llist constructors." << endl;
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;
  //cout << "Finish contructing a new list." << endl;
}

llist::~llist()
{ 
  if(isEmpty() == false)
  {
    //cout << "\nCalling the llist destructor." << endl; 
    while(isEmpty() == false)
    {
      Node *temp = this->Front;
      //cout << "Removing element: " << temp->Elem << " at " << temp << endl;
      deleteFront(temp->Elem);
    }
    //cout << "Object destroyed, and resources released." << endl;
  }
  else 
  {
    //cout << "\nCalling the llist destructor." << endl;
    //cout << "No action required: The list is already empty." << endl;
  }
}

//PURPOSE: Return true if Front and Rear are both pointing to NULL and Count is 0
//PARAMETER: Nothing is in the isEmpty parameter
bool llist::isEmpty()
{
  if (this->Front == NULL && this->Rear == NULL && this->Count == 0)
    return true;
  else 
    return false;
} 

//PURPOSE: Display each element of the list starting from Front to Rear, enclosed in [ ]
//PARAMETER: Nothing is in the displayAll function parameter
void llist::displayAll()
{
  if(isEmpty() == true)
    cout << "[ empty ]" << endl;
  else 
  {
    cout << "[ ";
    Node* Display_p = this->Front;
    while(Display_p != NULL)
    {
      cout << Display_p->Elem << " ";
      Display_p = Display_p->Next;
    }
    cout << "]" << endl;
  }
}  

//PURPOSE: Adding new node to the rear of the linked list.
//PARAMETER: pass in an int element from main and use it to create a new node that added to the rear.
void llist::addRear(el_t NewNum)
{
  Node* New_node = new Node;
  New_node->Elem = NewNum;
  New_node->Next = NULL;
  if (isEmpty() == true) //special case
  {
    this->Front = New_node; //updated front and rear to new node
    this->Rear = New_node;
    this->Count ++; //update count
  }
  else //regular case
  {
    this->Rear->Next = New_node; //add new node
    this->Rear = New_node; //updated rear
    this->Count ++; //updated count
  }
} 

//PURPOSE: Adding new node to the front of the linked list.
//PARAMETER:  pass in an int element from main and use it to create a new node that added to the front.
void llist::addFront(el_t NewNum)
{
  Node* New_node = new Node;
  New_node->Elem = NewNum;
  New_node->Next = NULL;
  if (isEmpty() == true) //special case
  {
    this->Front = New_node; //updated front and rear to new node
    this->Rear = New_node;
    this->Count ++; //update count
  }
  else
  {
    New_node->Next = this->Front; //add new node to the front
    this->Front = New_node; //updated front
    this->Count ++; //update count
  }
}

//PURPOSE: delete the front element
//PARAMETER: give back the front node element through OldNum (pass by reference)
void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty() == true) //error case
    throw Underflow();
  else if (this->Count == 1) //special case
  {
    Node *temp = this->Front; //temp point to front node
    OldNum = temp->Elem; //assign front element to OldNum 
    delete temp; //delete temp node
    this->Front = this->Rear = NULL; //set front and rear to null
    this->Count --;
  }
  else //regular case
  {
    Node *temp = this->Front; //temp point to front node
    OldNum = temp->Elem; //assign rear element to OldNum 
    this->Front = this->Front->Next; //Front point to the next node
    delete temp; //delete temp node
    this->Count --;
  }
} 

//PURPOSE: delete the rear element
//PARAMETER: give back the rear node element through OldNum (pass by reference)
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty() == true) //error case
    throw Underflow();
  else if (this->Count == 1) //special case
  {
    Node *temp = this->Rear; //temp point to front node
    OldNum = temp->Elem; //assign rear element to OldNum 
    this->Front = this->Rear = NULL; //set front and rear to null
    delete temp; //delete temp node
    this->Count --;
  }
  else //regular case
  {
    Node *Current_node = this->Front; //temp point to front node
    while (Current_node->Next != this->Rear)
    {
      Current_node = Current_node->Next; 
    } //loop until current_node is the node before the rear
    Node *temp = this->Rear;
    OldNum = temp->Elem; //assign rear element to OldNum 
    this->Rear = Current_node; //rear = node before temp
    this->Rear->Next = NULL; //set Rear Next to null
    delete temp; //delete temp node
    this->Count --;
  }
} 

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ 
  // moves temp J-1 times to go to the Jth node  
  temp = this->Front;
  for (int i = 1; i <= J - 1; i ++) 
  {
    temp = temp->Next;
  }
}

//PURPOSE: Remove the node at a specified position (Ith) in the linked list
//PARAMETER: I specifies the index (position) of the node that should be deleted from the linked list.
//OldNum used to store the value of the node being deleted
void llist::deleteIth(int I, el_t& OldNum) 
{
  //must use moveTo to move local pointers. 
  //Be sure to comment to which node you are moving them. Do not forget to set OldNum.
  if (I < 1 || I > this->Count) //error case
    throw OutOfRange();
  else if(I == 1) //special case 1
    deleteFront(OldNum);
  else if(I == this->Count) //special case 2
    deleteRear(OldNum);
  else //regular case
  {
    Node *temp; //local pointer
    moveTo(I, temp); //call moveTo function to traverse and save the deleted Node to temp.
    OldNum = temp->Elem; //save deleted number into OldNum.

    Node *previous_node;
    moveTo(I - 1, previous_node);
    previous_node->Next = temp->Next; //connect the node before deleted node with the node after deleted node
    delete temp;
    this->Count --;
  }
}   

//PURPOSE: Insert the node at a specified position (Ith) in the linked list
//PARAMETER: I specifies the index (position) of the node that should be inserted to the linked list.
//newNum used to store the value of the node being inserted
void llist::insertIth(int I, el_t newNum)
{
  //must use moveTo to move local pointers. Be sure to comment to which node you are moving them.
  if (I < 1 || I > this->Count + 1) //error case , count + 1 since it possible to insert new node after the rear
    throw OutOfRange();
  else if (I == 1) //special case 1
    addFront(newNum);
  else if (I == this->Count + 1) //special case 2
    addRear(newNum);
  else 
  {
    Node *temp; //local pointer
    moveTo(I, temp); //call moveTo function to travsere and save the deleted Node to temp.

    Node *new_node = new Node; //declare new node
    new_node->Elem = newNum;
    new_node->Next = NULL;

    Node *previous_node;
    moveTo(I - 1, previous_node);
    previous_node->Next = new_node; //Insert new node between previous node and temp
    new_node->Next = temp;
    this->Count ++;
  }
} 

//PURPOSE: Construct a new llist object that is an exact copy of an existing llist object referred to as Original
//PARAMETER: The Original object serves as the source of data for creating the new linked list.
llist::llist(const llist& Original) 
{
  //cout << "Calling the copy constructor." << endl;
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;
  Node* original_node = Original.Front;
  while(original_node != NULL)
  {
    //cout << "Copy element: " << original_node->Elem << " from " << original_node << endl; //so I can keep track of what element and where is adding to the new list
    this->addRear(original_node->Elem);
    original_node = original_node->Next;
  }
  //cout << "Finish copy constructor" << endl;
} //use my code

//PURPOSE: Allow one llist object to be assigned the values and structure of another llist object
//PARAMETER: OtherOne is the source object whose data and structure will be assigned to 
//the object on the left side of the assignment operator.
llist& llist::operator=(const llist& OtherOne)
{
  if(this != &OtherOne) //comparing the address of the lhs list with the rhs to make sure the two list is different
  {
    while(this->isEmpty() == false)
    {
      el_t oldNum;
      this->deleteRear(oldNum);
    }
    Node* otherone_node = OtherOne.Front;
    while(otherone_node != NULL)
    {
      this->addRear(otherone_node->Elem);
      otherone_node = otherone_node->Next;
    }
  }
  else
    cout << "Lhs list and rhs list is the same, can not applied = operator." << endl;
  return *this;
} // use my code
