//
//  main.cpp
//  Project3
//
//  Created by Samuel Donner on 10/20/15.
//  Copyright (c) 2015 Samuel Donner. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//doesn't work with one letter

bool isRouteWellFormed(string route)
{
    // integer to count the number of times a number appears after a alpha character
    int integerCounter = 0;
    
    // if statement to check if the first character in the string is either N,S,E, or W
    if( toupper(route[0])=='N' || toupper(route[0])=='S' || toupper(route[0])=='E' || toupper(route[0])=='W' )
    {
        // for loop to go through the string
        for (int i = 1; i != route.size(); i++)
        {
            
            // if statement to set integerCounter to 0 if an alpha character appears
            if( isalpha(route[i]) && (toupper(route[i])=='N' || toupper(route[i])=='S' || toupper(route[i])=='E' || toupper(route[i])=='W'))
            {
                integerCounter = 0;
            }
            
            if( !isalnum(route[i]) )
            {
                return false;
            }
            
            // if statement returns false if alpha is not NSEW
            if(isalpha(route[i]) && (toupper(route[i])!='N' && toupper(route[i])!='S' && toupper(route[i])!='E' && toupper(route[i])!='W'))
            {
                return false;
            }
            
            // if statement to add 1 to integerCounter every time an integer is present
            if(isnumber(route[i]))
            {
                integerCounter++;
            }
            
            // if statement to return false if integerCounter = 3
            if(integerCounter == 3)
            {
                return false;
            }
            
            // if statement to check if the for loop has finished the array
            if(i == route.size()-1)
            {
                return true;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    string robotPath;
    cin >> robotPath;
    cout << "isRouteWellFormed returned: " << isRouteWellFormed(robotPath);
}
