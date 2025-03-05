// #pragma once // Microsoft Visual Studios thing. It doesn't work with every compiler
// using namespace std; is not being used, since this isn't a standalone file and does not run alone

// Header Guard - Keeps compiler from declaring the header file more than once
#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>
#include <string>

class Book
{
    private:
        std::string bookTitle {};
        double price {};
        int quantity {};
        std::string descripion {};

    public:
        Book();
        Book(std::string bookTitle, std::string description, double price, int quantity);

        // Setters and Getters
        void SetTitle(std::string bookTitle);   // Titles
        std::string GetTitle() const;

        void SetDescription(std::string description);   // Descriptions
        std::string GetDescription() const;

        void SetPrice(double price);    // Prices
        double GetPrice() const;

        void SetQuantity(int quantity);  // Quantity
        int GetQuantity() const;

        // Printers
        void PrintBookTitleAndCost() const;
        void PrintBookDescription() const;

        // Overloads for <<, >>, cout, and cin
        friend std::ostream& operator<< (std::ostream& output, const Book& book);
        friend std::istream& operator>> (std::istream& input, Book& book);

        // Overload relational operators
        //friend bool operator==(const Book& lhs, const Book& rhs);  
        bool operator==(const Book& rhs);  // friend is not strictly required if you're only doing rhs with a bool 
        bool operator!=(const Book& rhs);
        bool operator<(const Book& rhs);
        bool operator>(const Book& rhs);

};


#endif // !_BOOK_H_

