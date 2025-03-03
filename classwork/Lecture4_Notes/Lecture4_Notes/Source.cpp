/* Jonah Shulske
 * 3/3/25
 * Lecture 4 - Classes, Spring 2025
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// CONSTRUCTOR OVERLOADING
/* Definition: Overloading allows multiple constructors with different parameter types
class Restaurant
{
    public:
        Restaurant();   // Default constructor
        Restaurant(string initName, int initRating);    // Overloaded constructor
};
 * Which constructor is called depends on the argument list.
 */

// CONSTRUCTORS WITH DEFAULT PARAMETER VALUES
/* Constructors can have default parameter values, making them function as default constructors
class Restaurant
{
    public:
        Restaurant(string initName = "NoName", int initRating = -1);
};
 * Benefits: Avoids the need for multiple overloaded constructors
 */

// CONSTRUCTOR INITIALIZER LINKS    
/* An alternative to initializing data members inside the constructor body.
class SampleClass
{
    public:
        SampleClass() : field1(100), field2(200) {}
};

 * Efficiency Considerations: Avoid constructing and then modifying objects by using initialization lists.
 */

// USING VECTORS WITH CLASSES
/* Vector of Objects: Managing a list of class objects using a vector
    vector<Review> reviewList;
    Review currentReview;

 * Class Design:
  Review Class: Handles ratings and comments
 * Reviews Class: Manages a collection of Review objects
 */

// DYNAMIC MEMORY ALLOCATION
/* Allocating Arrays of Objects: Using the new operator to dynamically allocate memory for arrays of objects.
    BloodPressure* pressureReadings = new BloodPresure[numReadings];
 *
 * Deallocating Memory: Use delete[] to free dynamically allocated arrays
    delete[] pressureReadings;
 */

// DYNAMICALLY ALLOCATING SINGLE OBJECTS
/* Dynamically allocate memory for a single object using new and access it with a pointer
    Sleep* sleepRecord = new Sleep(4, 37);
 *
 * Pointer Access: Using -> to access members
    sleepRecord->Print();
 * Deallocating Single Objects:
    delete sleepRecord;
 */

// ADDITIONAL CLASS DESIGN PRACTICES
/* Using classes within classes: Example of using a Reviews object inside a Restaurant class to manage multiple reviews
 * Decomposing programs into classes: Break down large problems into smaller classes (SoccerTeam consisting of Person objects) 
 */