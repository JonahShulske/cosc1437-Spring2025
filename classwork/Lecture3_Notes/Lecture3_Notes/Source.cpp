/* Jonah Shulske
 * Lecture 3 Notes
 * 2/24/25 + 2/26/25 Spring 2025
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// INTRODUCTION TO OBJECTS IN PROGRAMMING
/* Definition of Objects:
 * General: In everyday life, an object is a tangible item.
 * Programming: An object is an instance of a class in object oriented programming (OOP). Encapsulates both state (attributes) and behavior (methods).
 * 
 * Components of an Object:
 * State (Attributes): Data stored in the object (variables)
 * Behavior (Methods): Actions that an object can perform (functions)
 */

// TRANSITION FROM PROCEDURAL TO OBJECT ORIENTED PROGRAMMING (OOP)
/* Procedural Programming: Data functions are separate. Data is passed between functions, oftening leading to
 * Lack of data integrity, Code duplication, and Difficulties in extending/upgrading programs.
 * 
 * Object Oriented Programming: Solves many issues by bundling data and functions within objects.
 */

// OVERVIEW OF OBJECT ORIENTED PROGRAMMING
/* Definition: A programming paradigm centered around objects.
 * Key benefits: Modular and reuseable code; and easier maintenance and organization 
 */

// CHARACTERISTICS OF OOP
/* Abstraction: Simplifies complex systems by focusing on what an object does, not how it does it.
 * 
 * Encapsulation: Bundles data and behavior, ensuring data integrity by restricting access. Promotes information hiding.
 * 
 * Inheritance: New classes (derived/child) inherit attributes and methods from existing classes base/parent).
 * Promotes code reuse and hierarchial structures
 * 
 * Polymorphism: Allows objects of different clases to be treated as instances of common superclass.
 * Enables flexibility with method overloading (same method name with different implementations). 
 */

// OBJECT RELATIONSHIPS IN OOP
/* Types of Relationships (using UML notation where applicable):
 * Composition: A "part of" relationship (room and house)
 * 
 * Aggregation: A "has a" relationship (course and students)
 * 
 * Dependency: A "uses a" relationship (browser and internet connection).
 * 
 * Association: Stronger mututal dependency (bees and flowers)
 * 
 * Inheritance: An "is a" relationship (square is a type of shape)
 */

// CREATING A SIMPLE CLASS
//
//class Car
//{
//    private:
//        string model;
//        int year;
//    public:
//        // Constructor
//        Car(string m, int y) : model(m), year(y) {}
//
//        // Mutator and Accessor
//        void setModel(string m) { model = m; }
//        string getModel() { return model; }
//
//        // Method
//        void displayInfo()
//        {
//            std::cout << "Model: " << model << ", Year: " << year << endl;
//        }
//};
/* Private Members: Data hidden from outside access (encapsulation)
 * Public Members: Methods that can access and modify the private members
 */

// HOW TO USE CLASSES
/* To use a class, you must
 * 1. Include the class header (in a separate file)
 * 2. Create an object of the class using its name
 * 
 * Understanding the API (Application Programming Interface). 
 * The class API includes its public member functions (methods) that define how the object can be used.
 */
//#include "MyClass.h"
//
//MyClass obj;    // Creating an object of MyClass
//obj.SomeMethod();   // Using a method defined in my class
//

// DEFINING A SIMPLE CLASS
/* A class definition usually includes
 * Data Members: Variables to store the state of the object.
 * Member Functions: Functions to define behavior of the object.
 */
//
//class Rectangle
//{
//    private:
//        double width;
//        double height;
//
//    public:
//        void SetDimensions(double w, double h)
//        {
//            width = w;
//            height = h;
//        }
//        double Area() { return (width * height); }
//};

// INLINE MEMBER FUNCTIONS
/* Inline Function: A member function defined inside the class definition can also be defined outside the class using the inline keyword
 */
//
// Inside Definition
//class Circle
//{
//    private:
//        double radius;
//    public:
//        // Inline inside class definition
//        double GetRadius() const { return radius; }
//};
//
// Outside Definition
//class Circle
//{
//    private:
//        double radius;
//    public:
//        double GetRadius() const;   // Declaration
//};
//// Inline definition outisde the class
//inline double Circle::GetRadius() const { return radius; }

// MUTATORS, ACCESSORS, AND PRIVATE HELPERS
/* Mutators: Methods that modify the object's state (SetDimensions() in the Rectangle class)
 * Accessors: Methods that provide access to the object's data (GetRadius())
 * Private Helpers: Internal methods used by the class, not accessable from outside
 */
//class Student
//{
//    private:
//        string name;
//    public:
//        // Mutator
//        void SetName(string n) { name = n; }
//
//        // Accessor
//        string GetName() const { return name; }
//};

// THE 'THIS' IMPLICIT PARAMETER
/* 'this' is a pointer to the current object. It's used to refer to the object's data members
 */
//class Box
//{
//    private:
//        double length;
//    public:
//        void SetLength(double length)
//        {
//            // 'this' distinguishes the member variable from the parameter
//            this->length = length;
//        }
//};

// INITIALIZATION AND CONSTRUCTORS
/* Constructor: A special member function called automatically when an object is created. Used to initialize data members
 */
//class Car
//{
//    private:
//        string brand;
//    public:
//        // Constructor with an initialization list
//        Car(string b) : brand(b) {}
//};

// SEPARATING CLASSES INTO HEADER FILES AND IMPLEMENTATION FILES
/* Header File (.h): Contains class declaration and member function prototypes.
 * Implementation File (.cpp): Contains member function definitions. 
 */

// Rectangle.h
//class Rectangle
//{
//    private:
//        double width, height;
//    public:
//        void SetDimensions(double w, double h);
//        double area();
//};

// Rectangle.cpp
//#include "Rectangle.h"
//
//void Rectangle::SetDimensions(double w, double h)
//{
//    width = w;
//    height = h;
//}
//
//double Rectangle::area() { return (width * height); }