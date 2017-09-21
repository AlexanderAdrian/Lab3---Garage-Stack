//
//  main.cpp
//  Lab3
//
//  Created by Alexander Adrian Cardozo on 10/15/16.
//  Copyright © 2016 Alexander Adrian Cardozo. All rights reserved.
//
//__PREPROCESSOR DIRECTIVES__
#include <iostream>
#include <string>
#include <fstream>
#include "garage.h"
#include "stack.h"

using namespace std;

//__MAIN FUNCTION__
int main()
{
 
    
    garage garage1;
    ifstream car_details;
    int lineIdentity;
    
    
    
    car_details.open("/Users/alexanderadrian/Documents/Text/CSI/5. Fall 2016/311 INFO/Labs/Lab3 - Garage Stack/Lab3/car_details.txt");
    if(!car_details)
    {
        cout << "error" << endl;
        return 1;
    }
    
    char status;
    
    /* Read in file lines loop for each car */
    // M A I N  L O O P  F O R  F I L E
    
    while(!car_details.eof())
    {
        car_details >> status >> garage1.carro.license; //read in file lines
        
        /*C a r (E n t r y / E x i t)  n e s t e d  i f s t a t e m e n t s */
        
        
        
        
        
        
        
        
        /*-- I --  CAR ARRIVING SCENARIO COMPLETE BELOW */
        if(status == 'a' )
        {
            cout << "The arriving car has licence: " << garage1.carro.license << endl;
            //Arrive Scenario 1. LINE 1 has room, then store in Line 1
            if( !garage1.line1.IsFull()  )   // There is space
            {
                //Store vehicle in line 1
                garage1.line1.push(garage1.carro);
                garage1.line1.display(1);

            }
            //Arrive Scenario 2. LINE 1 is full, Line 2 is not, store in Line 2
            else if(garage1.line1.IsFull() && !garage1.line2.IsFull() )
            {
               //Store car in line 2
                garage1.line2.push(garage1.carro);
                garage1.line2.display(2);

            }
            //Arrive Scenario 3. LINE 1 FULL/Line 2 FULL, NOPARK
            else
            {
                cout << "Garage is full, you cannot park here. " << endl;
            }
        }/*CAR ARRIVING -SHUT-*/
        
        
        
        
        
        
        
        
        
        
        
        
        

        /*-- II -- CAR LEAVING SCENARIO COMPLETE BELOW */
        else
        {
            cout << "The car with license: " << garage1.carro.license << " is trying to exit." << endl;
            int qTop; // Holds Top item
            
            
            /* t h e r e  d e c l a r e d */
            //Run search in line1/line2, store in variable: there
            int there1 = garage1.line1.search(garage1.carro, qTop);
            cout << "there1 is: " << there1 << endl;
            int there2 = garage1.line2.search(garage1.carro, qTop);
            cout << "there2 is: " << there2 << endl;
            
            
            /*----------------------LINE 1 -----------------------*/
            
            //__I__ LOOP FOR car present in LINE1
            if(there1 != -1)
            {
                lineIdentity = 1; //set lineIdentity for loop section
                //__II__ IF car is right on top, POP car out of line1
                if(there1 == qTop)
                {
                    cout << "The Car with: " << garage1.carro.license << "is in Lane 1 and was driven out."
                    << "it was moved: " << garage1.line1.Top().moves  << " times" << endl;
                    garage1.line1.pop();   //pop out car if on top of line1
                    
                }
                //__III___ IF car is in line1, but not on top, use moveOut procedire
                //run procedure with lineIdentity == 1
                else
                {
                    cout << "There are cars in the way, use moveout proc (LINE 1) " << endl;
                    cout << "it was moved: " << garage1.line1.Top().moves  << " times" << endl;
                    garage1.moveOut(there1,  qTop, lineIdentity);
                    garage1.line1.pop();
                    garage1.backFromStreet();

                    
                        
                    
                }
            }//loop for car one present in LINE1 -SHUT-
            
            
            /*---------------------LINE 2 ---------------------*/
            
            //__IV__ IF car not in line1, START Here
            else if(there2 != -1)
            {
                lineIdentity = 2; //set lineIdentity for loop section
                //__II__ IF car is right on top, POP car out of line1
                if(there2 == qTop)
                {
                    cout << "The Car with: " << garage1.carro.license << "is in Lane 1 and was driven out."
                    << "it was moved: " << garage1.line2.Top().moves  << " times" << endl;
                    garage1.line2.pop();   //pop out car if on top of line1
                    
                }
                //__III___ IF car is in line1, but not on top, use moveOut procedire
                //run procedure with lineIdentity == 1
                else
                {
                    cout << "There are cars in the way, run move proc (LINE2) " << endl;
                    cout << "it was moved: " << garage1.line2.Top().moves  << " times" << endl;

                    garage1.moveOut(there2,  qTop, lineIdentity);
                    garage1.line2.pop();
                    garage1.backFromStreet();
                    
                }
            }//loop for car present in LINE2 -SHUT-
                
           /*-----------------NEITHER LINE --------------------*/
            else
                {
                    cout << "Car is not present in garage, cannot retrieve." << endl;
                }
                
                
                
                
                
                
            
            
            
        }/* CAR LEAVING SCENARIO -SHUT- */
        
        
    }/* WHILE(CARDETAILS) File -SHUT- */
    
    
    
    
    
}/* MAIN() -SHUT- */



/* OUTPUT BELOW: */


/* 
 
 
 The arriving car has licence: 10009
 Line 1:
 0 10009
 The arriving car has licence: 10008
 Line 1:
 0 10009
 1 10008
 The arriving car has licence: 10007
 Line 1:
 0 10009
 1 10008
 2 10007
 The arriving car has licence: 10006
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 The arriving car has licence: 10005
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 The arriving car has licence: 10004
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 The arriving car has licence: 10003
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 The arriving car has licence: 10012
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 7 10012
 The arriving car has licence: 10013
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 7 10012
 8 10013
 The arriving car has licence: 10015
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 7 10012
 8 10013
 9 10015
 The arriving car has licence: 10016
 Line 2:
 0 10016
 The arriving car has licence: 10017
 Line 2:
 0 10016
 1 10017
 The arriving car has licence: 10018
 Line 2:
 0 10016
 1 10017
 2 10018
 The arriving car has licence: 10019
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 The arriving car has licence: 10020
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 The arriving car has licence: 10021
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 The arriving car has licence: 10022
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 The arriving car has licence: 10023
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 The arriving car has licence: 10024
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 The arriving car has licence: 10025
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 The car with license: 10009 is trying to exit.
 We are in search qTop = 9
 Top is: 9
 there1 is: 0
 there2 is: -1
 There are cars in the way, use moveout proc (LINE 1)
 it was moved: 0 times
 popped vehibile is: 10015 and top is 8
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 7 10012
 8 10013
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10013 and top is 7
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 7 10012
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10012 and top is 6
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 6 10003
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10003 and top is 5
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 5 10004
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10004 and top is 4
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 4 10005
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10005 and top is 3
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 3 10006
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10006 and top is 2
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 2 10007
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10007 and top is 1
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 1 10008
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10008 and top is 0
 Moving car from line 1 to the street.
 Line 1:
 0 10009
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 popped vehibile is: 10009 and top is -1
 BACK FROM STREET()
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 4 10004
 5 10005
 6 10006
 7 10007
 8 10008
 while
 popped vehibile is: 10008 and top is 7
 Moving cars from street to line 1
 Line 1:
 0 10008
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 4 10004
 5 10005
 6 10006
 7 10007
 while
 popped vehibile is: 10007 and top is 6
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 4 10004
 5 10005
 6 10006
 while
 popped vehibile is: 10006 and top is 5
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 4 10004
 5 10005
 while
 popped vehibile is: 10005 and top is 4
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 4 10004
 while
 popped vehibile is: 10004 and top is 3
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 4 10004
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 3 10003
 while
 popped vehibile is: 10003 and top is 2
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 4 10004
 5 10003
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 2 10012
 while
 popped vehibile is: 10012 and top is 1
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 4 10004
 5 10003
 6 10012
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 1 10013
 while
 popped vehibile is: 10013 and top is 0
 Moving cars from street to line 1
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 4 10004
 5 10003
 6 10012
 7 10013
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 0 10015
 while
 popped vehibile is: 10015 and top is -1
 Moving cars from street to line 1 
 Line 1:
 0 10008
 1 10007
 2 10006
 3 10005
 4 10004
 5 10003
 6 10012
 7 10013
 8 10015
 Line 2:
 0 10016
 1 10017
 2 10018
 3 10019
 4 10020
 5 10021
 6 10022
 7 10023
 8 10024
 9 10025
 Line 3:
 The car with license: 10008 is trying to exit.
 We are in search qTop = 8
 Top is: 8
 there1 is: 0
 there2 is: -1
 There are cars in the way, use moveout proc (LINE 1) 
 it was moved: 2 times
 popped vehibile is: 10015 and top is 7
 Moving car from line 1 to the street. 

 
 
 
 */


