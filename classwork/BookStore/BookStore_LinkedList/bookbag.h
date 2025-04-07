#ifndef _BOOKBAG_H_
#define _BOOKBAG_H_

#include <iostream>
#include <string>
#include <climits>
#include "book.h"
#include "linkedlist.h"

class BookBag
{
private:
    std::string customerName;
    std::string currentDate;    // Don't actually use a string for real programming. This is being done out of laziness
    LinkedList books;

public:
    BookBag(std::string customerName, std::string currentDate);

    // Getters
    std::string GetCustomerName() const;
    std::string GetCurrentDate() const;

    // BookBag actions
    void AddBook(Book book);
    void RemoveBook(std::string title, std::string description);
    void RemoveBook(Book book);
    void ModifyBook(const Book& book);  // This will only change the price or quantity

    // Information about the bag
    int GetNumBooksInBag() const;   // Total of all books
    double GetCostOfBag() const;
    int GetUniqueBookCount() const;     // Number of each unique books

    void PrintTotal() const;
    void PrintDescriptions() const;


    // Operator Overloading
    friend std::ostream& operator<<(std::ostream& outprint, const BookBag& bag);

    BookBag operator+(BookBag rhs);
    BookBag operator+(Book rhs);    // PLUS
    BookBag operator-(Book rhs);    // MINUS

    Book& operator[](int index);
};








#endif _BOOKBAG_H_
