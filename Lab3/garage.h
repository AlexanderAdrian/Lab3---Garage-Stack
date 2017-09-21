//
//  garage.h
//  Lab3
#ifndef Header2_h
#define Header2_h
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;





class garage
{
    
    public:
    
    
    /*Stack Items*/
    Stack line1;
    Stack line2;
    Stack street;
    
    
    car carro;
    
    // moves constructor
    garage()
    {
        carro.moves = 0;
    }
    
    
    /*FUNCTIONS*/
    
    
    
    //Departure Function
    
    //HELPER FUNCTION
    
    
    void moveOut(int there, int qTop, int identity );
    void backFromStreet();
};



    
void garage:: moveOut(int there, int qTop, int identity )
    {
        car Temp;
        
        
        for(int i = qTop; i > there; i--)
        {
            //If in line 1
            if(identity == 1)
            {
                if(!line2.IsFull())
                {
                    Temp = line1.Top();
                    Temp.moves++;
                    line2.push(Temp);
                    line1.pop();
                    cout << "Moving car from line 1 to line 2 " << endl;
                    line1.display(1);
                    line2.display(2);

                    
                }
                else
                {
                    Temp = line1.Top();
                    Temp.moves++;
                    street.push(Temp);
                    line1.pop();
                    cout << "Moving car from line 1 to the street. " << endl;
                    line1.display(1);
                    line2.display(2);

                }
                
            }
            //If in line 2
            else if(identity == 2)
                
            {
                if(!line1.IsFull())
                {
                    Temp = line2.Top();
                    Temp.moves++;
                    line1.push(Temp);
                    line2.pop();
                    cout << "Moving car from line 2 to line 1. " << endl;
                    line2.display(1);
                    line2.display(2);
                }
                else
                {
                    Temp = line2.Top();
                    Temp.moves++;
                    street.push(Temp);
                    line2.pop();
                    cout << "Moving car from line 2 to street. " << endl;
                    line2.display(1);
                    line2.display(2);


                }
                
            }
            
           
        }
        
            }
        
void garage::backFromStreet()
{
    car Temp;
    cout << "BACK FROM STREET()" << endl;
    street.display(3);
        while(!street.IsEmpty())
        {
            cout<<"while"<<endl;
            if(!line1.IsFull())
            {
                Temp = street.Top();
                Temp.moves++;
                line1.push(Temp);
                street.pop();
                cout << "Moving cars from street to line 1 " << endl;
                line1.display(1);
                line2.display(2);
                street.display(3);

            }
            else
            {
                Temp = street.Top();
                Temp.moves++;
                line2.push(Temp);
                street.pop();
                cout << "Moving cars from street to line 2. " <<  endl;
                line1.display(1);
                line2.display(2);
                street.display(3);

            }
        }
}
    


    
    
    

    
    
    
    










#endif /* Header2_h */
