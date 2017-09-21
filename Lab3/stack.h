// file Stack.h
// array stack implementation
#ifndef Stackh
#define Stackh
#include <iostream>
#include <cstdlib>
#include "garage.h"
#include <string>

using namespace std;




/*---------------------------  Car Struct definition ----------------------------------*/


struct car
{
    
    
    
    //--Car Items--
    string license;
    int moves = 0;
    
    
    /* Check Later
     
     //--Overloaded Car Output stream opperator --
     friend ostream& operator <<(ostream& outs, const car& car1);
     
     */
    
};







/* check later
 
 ostream& operator<<(ostream & outs, const car& car1) //outs << for operator,
 // car& for item in PlainBox
 {
 return outs << car1.license;           //print with outs << source.item
 }
 
 
 
 
 */











/*---------------------------  Stack Definition -------------------------*/





typedef car StackType;
class Stack

{
    // LIFO objects
    
public:
    Stack(int MaxStackSize = 10);
    ~Stack() {delete [] stack;}
    
    /*INLINE full/empty functions */
    bool IsEmpty() const {return top == -1;}
    bool IsFull() const {return top == MaxTop;}
    
    
    
    
    StackType Top() const;
    void push(const StackType & x);
    void pop();
    void display(int x);
    
    //Search Function
    int search(const StackType& x, int& qTop);
    
    
    
    
    
    
private:
    int top;    // current top of stack
    int MaxTop; // max value for top
    StackType *stack;   // element array is pointer 
};

void Stack::display(int x)
{
    cout<<"Line "<< x << ":" <<endl;
    for(int i = 0; i <= top; i++)
        cout << i << " " << stack[i].license << endl;
}


//CONSTRUCTOR: Sets Max stack size to 10 
Stack::Stack(int MaxStackSize)
{
    //Pre: none'
    //Post: Array of size MaxStackSaize to implement stack
    // Stack constructor.
    MaxTop = MaxStackSize - 1;
    stack = new StackType[MaxStackSize];
    top = -1;
}




//RETURN TOP ITEM, or EMPTY
StackType Stack::Top() const
{
    //Pre: stack is not empty
    // Post:  Returns top element.
    if (IsEmpty())
        throw logic_error ("Top fails: Stack is empty");// Top fails
    return stack[top];
}



//PUSH
void Stack::push(const StackType & x)
{
    //Pre: Stack is not full
    //Post: Push x to stack.
    //		Stack has one more element
    if (IsFull()) throw logic_error("Push fails: full stack"); // Push fails
    stack[++top] = x;    // Combines two statements into 1, using pre-increment 
}


//POP
void Stack::pop()
{
    //Pre: Stack is not Empty
    //Post: Stack has one less element
    if (IsEmpty()) {
        throw logic_error ("Pop fails: Stack is empty");
    }; // Pop fails
    top--;

    cout << "popped vehibile is: " << stack[top+1].license << " and top is " << top << endl;
}



// Search Function
int Stack::search(const StackType& x, int& qTop)
{
    
    for(int i = 0; i < top; i++)
    {
        if( stack[i].license == x.license)  //determine position if object is present    OVERLOAD
        {
                 //return i; location of entry in array
            qTop = top;
            cout << "We are in search" << " qTop = " << qTop << endl;
            cout << "Top is: " << top << endl;
            return i;
        }
        
    }return -1; //if not present return -1 
}





#endif
