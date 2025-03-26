/* Jonah Shulske
 * 3/24/25 Spring 2025
 * Lecture 6 - Dynamic Classes
 */

// 1. INTRODUCTION TO DYNAMICALLY ALLOCATED ARRAYS IN CLASSES
/* Key Concepts
    * Some classes need to handle collections of data whose size isn't known until runtime.
    * Arrays with extra capacity help manage frequent resizing operations
 * 
 * 3 Key Members for Dynamic Arrays
    * Pointer: Holds the address of the dynamically allocated array
    * Capcaity: Maximum number of the elements the array can hold
    * Size: Number of elements currently stored in the array.
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
    * A class constructor should initialize the dynamic array with an initial capacity (often 10 for efficient memory use)
    * The constructor dynamically allocates the array and sets the size to 0, meaning it's empty, but ready to store data.
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
        * Allocating a new, larger array (typically twice the size of the current array)
        * Copying existing elements into the new array.
        * Deleting the old array and pointing the array pointer to the new one.
 *
 * Example: The IncreaseCapacity() function doubles the capacity, creates a new array, copies data, and deletes the old array.
 */

// 4. EFFICIENT MEMORY MANAGEMENT: DESTRUCTORS
/* Role of a Destructor:
    * Destructors are crucial for avoiding memory leaks by ensuring all dynamically allocated memory is deallocated when an object is destroyed.
    * When an object of a class with dynamic memory goes out of scope, the destructor is automatically called.
 *
 * Example: The ~ActivityTracker() destructor is responsible for releasing the memory allocated for the activities array.
 */

// 5. COMMON MISTAKES AND SOLUTIONS IN DYNAMIC MEMORY MANAGEMENT
/* Memory Leaks:
    * Memory leaks occur when dynamically allocated memory is not freed, causing the program to consume more memory over time.
    * Solution: Always ensure that dynamically allocated memory is deallocated in the destructor.
 *
 * Copy Constructor and Assignment Operator:
    * The default copy constructor and assignment operator perform shallow copies, leading to multiple objects pointing to the same memory.
    * Deep Copy: For classes with dynamically allocated memory, you need to define a copy constructor and assignment operator to perform deep copies.
 *
 * Example: The ActivityTracker class should have a copy constructor that duplicates the dynamic array when copying an object, ensuring that the new object owns its own separate memory.
 */

// 6. RULE OF THREE
/* Rule of Three: If a class requires a destructor, it likely also needs a copy constructor and an assignment operator.
    * Dynamically allocated data needs to be carefully managed when objects are copied or assigned to ensure that memory is properly handled.
 *
 * Example: If an ActivityTracker object is copied without a copy constructor, both the original and copy would point to the same activities array. 
    * Deleting one would invalidate the array for the other, leading to runtime errors.
 */

// PRACTICAL EXAMPLE: ACTIVITYTRACKER CLASS IN USE
/* Adding Activies: When adding activities to the tracker, if space is available, the new data is simply added. Otherwise, the array is expanded first.
    * The member function AddActivity() checks if there's space and calls IncreaseCapacity() if needed.
 *
 * Calculating Steps Per Hour: 
    * The CalcStepsPerHour() function iterates through the ActivityTracker array and calculates the number of steps walked per hour based on total steps and total seconds. 
 */

// 8. COPY CONSTRUCTORS AND ASSIGNMENT OPERATORS
/* Default Behavior: The default behavior of the copy constructor is to perform shallow copies.
    * For dynamically allocated data, this can cause issues, as multiple objects may share the same memory.
 *
 * Custom Copy Constructor: A custom copy constructor should allocate new memory and copy the contents from the original object.
 * 
 * Assignment Operator: Similar to the copy constructor, it should be overloaded to ensure deep copying.
 */

// 9. MEMORY LEAKS AND GARBAGE COLLECTION
/* Memory Leaks: Failing to deallocate dynamically allocated memory results in memory leaks.
    * Garbage Collection: Some languages, like Java, handle memory automatically via garbage collection. C++ requires explicit memory management.
 *
 * Avoiding Leaks: Always deallocate memory in the destructor.
    * Use smart pointers (unique_ptr, shared_ptr) in modern C++ to simplify memory management and avoid leaks. 
 */

// 10. BEST PRACTICES FOR MANAGING DYNAMICALLY ALLOCATED DATA
/* Allocate Memory in Powers of Two - For performance reasons when resizing dyanmic arrays
 * Always Define a Destructor, Copy Constructor, and Assignment Operator (Rule of Three) - When managing dynamic memory.
 * Use Smart Pointers - In modern C++ for automatic memory management and to prevent memory leaks.
 */