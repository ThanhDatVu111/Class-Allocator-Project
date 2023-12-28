#ifndef A
#define A
#include <iostream>
#include <string>
using namespace std;

class el_t
{
  private:  // these will change depending on the client needs
    string key;  // key -- for EC, key has to change to string everywhere!!!
    string name;  // customer name
    int age;  // customer age
    int studentID;  // customer ID

  public:
    el_t();  // to create a blank el_t object (default constructor)
    el_t(string, string, int, int); // to create an initialized el_t object - useful for the client 
                                    // ** add more arguments to create the object

    // The following functions are available to the htable class to be able to
    // use different el_t without modifying the code
    string getkey(); // only the key part can be accessed by the user of this class.
    void setkey(string); // only the key part can be accessed by the user of this class.

    // In linked list search, == is used to compare node elements
    // but what does it mean for this client to compare node elements?  
    bool operator==(el_t);  // overload == for search
    bool operator!=(el_t);  // overload != for search

    // This overloads cout for the el_t object
    // This is a friend function since the receiver object is not el_t
    friend ostream& operator<<(ostream&, const el_t&);
};
#endif
