#include "book.h"

Book::Book()
{
}

Book::Book(std::string bookTitle, std::string description, double price, int quantity)
{
}

void Book::SetTitle(std::string bookTitle)
{
}

std::string Book::GetTitle() const
{
    return std::string();
}

void Book::SetDescription(std::string description)
{
}

std::string Book::GetDescription() const
{
    return std::string();
}

void Book::SetPrice(double price)
{
}

double Book::GetPrice() const
{
    return 0.0;
}

void Book::SetQuantity(int quantity)
{
}

int Book::GetQuantity() const
{
    return 0;
}

void Book::PrintBookTitleAndCost() const
{
}

void Book::PrintBookDescription() const
{
}

bool Book::operator==(const Book & rhs)
{
    return false;
}

bool Book::operator!=(const Book & rhs)
{
    return false;
}

bool Book::operator<(const Book & rhs)
{
    return false;
}

bool Book::operator>(const Book & rhs)
{
    return false;
}

std::ostream & operator<<(std::ostream & output, const Book & book)
{
    // TODO: insert return statement here
}

std::istream & operator>>(std::istream & input, Book & book)
{
    // TODO: insert return statement here
}
