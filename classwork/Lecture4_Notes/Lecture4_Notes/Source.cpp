/* Jonah Shulske
 * 3/3/25
 * Lecture 4 - Classes, Spring 2025
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// CONSTRUCTOR OVERLOADING
/* Definition: Overloading allows multiple constructors with different "1" types
class Restaurant
{
    public:
        Restaurant();   // Default constructor
        Restaurant(string initName, int initRating);    // Overloaded constructor
};
 * Which constructor is called depends on the "2" list.
 */

// CONSTRUCTORS WITH DEFAULT PARAMETER VALUES
/* Constructors can have default parameter values, making them function as "3" constructors
class Restaurant
{
    public:
        Restaurant(string initName = "NoName", int initRating = -1);
};
 * Benefits: Avoids the need for "4" overloaded constructors
 */

// CONSTRUCTOR INITIALIZER LINKS    
/* An alternative to initializing data members inside the constructor body.*/