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
}

int BookBag::GetNumBooksInBag() const
{
    return 0;
}

double BookBag::GetCostOfBag() const
{
    return 0.0;
}

int BookBag::GetUniqueBookCount() const
{
    return 0;
}

void BookBag::PrintTotal() const
{
}

void BookBag::PrintDescriptions() const
{
}

BookBag BookBag::operator+(BookBag rhs)
{
    return BookBag();
}

BookBag BookBag::operator+(Book rhs)
{
    return BookBag();
}

BookBag BookBag::operator-(Book rhs)
{
    return BookBag();
}

Book & BookBag::operator[](int index)
{
    // TODO: insert return statement here
}

std::ostream & operator<<(std::ostream & outprint, const BookBag & bag)
{
    // TODO: insert return statement here
}
