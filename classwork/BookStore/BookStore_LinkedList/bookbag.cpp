#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "bookbag.h"

BookBag::BookBag(std::string customerName, std::string currentDate) : customerName(customerName), currentDate(currentDate) {}

std::string BookBag::GetCustomerName() const
{
    return customerName;
}

std::string BookBag::GetCurrentDate() const
{
    return currentDate;
}

void BookBag::AddBook(Book book)
{
    for (Book& aBook : books)
        if (aBook == book)
        {
            aBook.SetQuantity(aBook.GetQuantity() + book.GetQuantity());
            return;
        }

    books.push_back(book);
}

void BookBag::RemoveBook(std::string title, std::string description)
{
    for (int index = 0; index < books.size(); ++index)
        if (books.at(index).GetTitle() == title && books.at(index).GetDescription() == description)
        {
            books.erase(books.begin() + index);
            break;
        }
}

void BookBag::RemoveBook(Book book)
{
    RemoveBook(book.GetTitle(), book.GetDescription());
}

void BookBag::ModifyBook(const Book & book)
{
    /* The only attributes that can be modified in a book are the price and quantity.
     * The parameter book should have a default title and description and only the price/quantity should be set to change. Will only look at price and quantity of book parameter.
    */ 

    Book defaultBook; // Create an instance a default book
    for (Book& aBook : books)
        if (aBook == book)   // Check which attributes to update (modify)
        {
            if (book.GetPrice() != defaultBook.GetPrice())
                aBook.SetPrice(book.GetPrice());

            if (book.GetQuantity() != defaultBook.GetQuantity())
                if (book.GetQuantity() == 0)
                    RemoveBook(aBook);
                else
                    aBook.SetQuantity(book.GetQuantity());
        }
}

int BookBag::GetNumBooksInBag() const
{
    // This is the total number of books including duplicates
    int total = 0;
    for (const Book& book : books)
        total += book.GetQuantity();

    return total;
}

double BookBag::GetCostOfBag() const
{
    // Total cost of all the books, including duplicates
    double total = 0.0;
    for (const Book& book : books)
        total += book.GetQuantity() * book.GetPrice();

    return total;
}

int BookBag::GetUniqueBookCount() const
{
    return books.size();
}

void BookBag::PrintTotal() const
{
    throw std::runtime_error("PrintTotal() not yet implemented");
}

void BookBag::PrintDescriptions() const
{
    throw std::runtime_error("PrintDescriptions() not yet implemented");
}

BookBag BookBag::operator+(BookBag rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;

    for (const Book& book : rhs.books)
        tempBag.AddBook(book);

    return tempBag;
}

BookBag BookBag::operator+(Book rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.AddBook(rhs);

    return tempBag;
}

BookBag BookBag::operator-(Book rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.RemoveBook(rhs);

    return tempBag;
}

Book & BookBag::operator[](int index)
{
    if (index < 0 || index >= books.size())
        throw std::runtime_error("Index out of range");

    return books[index];            // Gets book at array of index   

    // books.at(index) is a balance checker and throws exception if out of range
}

std::ostream & operator<<(std::ostream & outprint, const BookBag & bag)
{
    if (bag.books.empty())
    {
        outprint << "BOOK BAG IS EMPTY";
        return outprint;
    }

    outprint << bag.customerName << "'s Book Bag -" << bag.currentDate << std::endl;
    outprint << "Number of books: " << bag.GetNumBooksInBag() << "\n" << std::endl;
    
    for (const Book& book : bag.books)
        outprint << book << std::endl;

    outprint << "\n" << "Total: $" << bag.GetCostOfBag();

    return outprint;
}
