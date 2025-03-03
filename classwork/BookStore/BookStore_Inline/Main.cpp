/* Jonah Shulske
 * 3/3/25 Spring 2025
 * BookStore_Inline
 * Program that will create a book class, instantiate a couple books, and output data
 * -------------------------------------
 * We're gonna place the entire class in one file and put main in the same file. Only time doing this
 */

#include <iostream>
#include <string>
using namespace std;    // No longer using after this project

class Book
{
    private:
        // Instance variables
        string bookTitle{};    // Assigns a default value
        double price{}; // Automatically at 0.0

    public:
        /* A constructor is a special method that has the following
         * Named exactly the same as the class (including case). Doesn't have a return type (not even void)
         * Can be overloaded to allow different initializations. The purpose is to initialize the instance variables
         * The compiler supplies a no parameter, default constructor if the programmer doesn't create their own, and does nothing
         */
        Book(string bookTitle, double price) : bookTitle(bookTitle), price(price) {}  // List initializer
        Book() : Book("", 0.0) {}   // Default construtor calling custom constructor

        // The method above is called inlining. Code for the method is located in the class definition (declaration)

        // More inlining
        void SetTitle(string bookTitle) { this->bookTitle = bookTitle; }

        string GetTitle() const { return bookTitle; }   // Const says object isn't being changed

        // Another way of doing inlining, and is better
        void SetPrice(double price);
        double GetPrice() const;

};

inline void Book::SetPrice(double price) { this->price = price; }
inline double Book::GetPrice() const { return price; }

int main()
{
    Book book1;
    book1.SetTitle("C++ for Dummies");
    book1.SetPrice(29.99);

    Book book2("All I Wanted Was a Pepsi", 7.99);

    std::cout << book1.GetTitle() << ": $" << book1.GetPrice() << endl;
    std::cout << book2.GetTitle() << ": $" << book2.GetPrice() << endl;
    return 0;
}