#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <stdexcept>
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
    for (int index = 0; index < books.GetSize(); ++index)
    {
        if (books.GetAt(index) == book)
        {
            Book temp = books.GetAt(index);
            temp.SetQuantity(books.GetAt(index).GetQuantity() + book.GetQuantity());
            books.SetAt(temp, index);
            return;
        }
    }
    books.AddToRear(book);
}

void BookBag::RemoveBook(std::string title, std::string description)
{
    for (int index = 0; index < books.GetSize(); ++index)
    {
        if (books.GetAt(index).GetTitle() == title && books.GetAt(index).GetDescription() == description)
        {
            books.RemoveAt(index);
            break;
        }
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
    for (int index = 0; index < books.GetSize(); ++index)
    {
        Book aBook = books.GetAt(index);
        if (aBook == book)      // check attributes to update
        {
            if (book.GetPrice() != defaultBook.GetPrice())
                aBook.SetPrice(book.GetPrice());

            if (book.GetQuantity() != defaultBook.GetQuantity())
            {
                if (book.GetQuantity() == 0)
                    RemoveBook(aBook);
                else
                    aBook.SetQuantity(book.GetQuantity());
            }

            if (book.GetQuantity() > 0)
                books.SetAt(aBook, index);

            break;
        }
    }
}

int BookBag::GetNumBooksInBag() const
{
    // This is the total number of books including duplicates
    int total = 0;
    for (int index = 0; index < books.GetSize(); ++index)
        total += books.GetAt(index).GetQuantity();

    return total;
}

double BookBag::GetCostOfBag() const
{
    // Total cost of all the books, including duplicates
    double total = 0.0;
    for (int index = 0; index < books.GetSize(); ++index)
        total += books.GetAt(index).GetQuantity() * books.GetAt(index).GetPrice();

    return total;
}

int BookBag::GetUniqueBookCount() const
{
    return books.GetSize();
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

    for (int index = 0; index < rhs.books.GetSize(); ++index)
        tempBag.AddBook(rhs.books.GetAt(index));

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
    if (index < 0 || index >= books.GetSize())
        throw std::runtime_error("Index out of range");

    Book temp = books.GetAt(index);
    return temp;
}

std::ostream & operator<<(std::ostream & outprint, const BookBag & bag)
{
    if (bag.books.IsEmpty())
    {
        outprint << "BOOK BAG IS EMPTY";
        return outprint;
    }

    outprint << bag.customerName << "'s Book Bag -" << bag.currentDate << std::endl;
    outprint << "Number of books: " << bag.GetNumBooksInBag() << "\n" << std::endl;
    
    for (int index = 0; index < bag.books.GetSize(); ++index)
        outprint << bag.books.GetAt(index) << std::endl;

    outprint << "\n" << "Total: $" << bag.GetCostOfBag();

    return outprint;
}
