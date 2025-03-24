/* Jonah Shulske
 * 3/24/25 Spring 2025
 * Chapter 6 - Dynamic Classes
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// 1. INTRODUCTION TO DYNAMICALLY ALLOCATED ARRAYS IN CLASSES

/* Key Concepts
    * Some classes need to handle collections of data whose size isn't known until runtime.
    * Arrays with extra capacity help manage frequent resizing operations
 * 
 * 3 Key Members for Dynamic Arrays
    * Pointer: Holds the (1) of the dynamically allocated array
    * Capcaity: Maximum (2) of the elements the array can hold
    * Size: Number of elements currently (3) in the array.
 *
 * Example: ActivityTracker Class
    * Activty Class: Manages individual activities with steps and seconds.
    * ActivityTracker Class: Manages an array of Activity objects
        * activities (pointer to dynamic array)
        * activitiesCapacity (total capacity of array)
        * activitiesSize (current size)
 */

// 2. INITIALIZING DYNAMICALLY ALLOCATED ARRAYS
/*  Constructor Design:
    * A class constructor should initialize the dynamic array with an initial capacity (often (4) for efficient memory use)
    * The constructor dynamically allocates the array and sets the (5) to 0, meaning it's empty, but ready to store data.
    * Initializing empty objects to hold placeholders in the array until actual data is provided.
 *  
 * Example:
    * When an ActivityTracker is initialized, it creates an array of Activity objects with an initial capacity.
    * Each Activity is initialized with default values, ex: steps = 0 and seconds = 0.
 */

// 3. ADDING AND MANAGING ELEMENTS IN DYNAMIC ARRAYS
/*  Expanding the Array:
    * Arrays must expand when they run out of capacity. (activitiesCapacity == activitiesSize)
    * Process involves: 
        * Allocating a new, larger array (typically (6) the size of the current array)
        * Copying existing elements into the new array.
        * Deleting the old array and pointing the array pointer to the new one.
 *
 * Example: The IncreaseCapacity() function doubles the capacity, creates a new array, copies data, and deletes the old array.
 */