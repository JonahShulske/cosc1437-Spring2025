#include "book.h"

Book::Book() : Book("none", "none", -1.0, -1) {}

Book::Book(std::string bookTitle, std::string description, double price, int quantity) : bookTitle(bookTitle), description(description), price(price), quantity(quantity) {}

void Book::SetTitle(std::string bookTitle)
{
    if (bookTitle.empty())
        throw std::runtime_error("Error: Book title cannot be blank");

    this->bookTitle = bookTitle;
}

std::string Book::GetTitle() const
{
    return bookTitle;
}

void Book::SetDescription(std::string description)
{
    if (description.length() == 0)
        throw std::runtime_error("Error: Description cannot be blank");

    this->description = description;
}

std::string Book::GetDescription() const
{
    return description;
}

void Book::SetPrice(double price)
{
    if (price < 0)
        throw std::runtime_error("Error: Price cannot be less than $0.00");

    this->price = price;
}

double Book::GetPrice() const
{
    return price;
}

void Book::SetQuantity(int quantity)
{
    if (quantity < 0)
        throw std::runtime_error("Error: Quantity cannot be less than 0");

    this->quantity = quantity;
}

int Book::GetQuantity() const
{
    return quantity;
}

void Book::PrintBookTitleAndCost() const
{
    std::cout << bookTitle << " " << quantity << " @ $" << price << " = " << (quantity * price);
}

void Book::PrintBookDescription() const
{
    std::cout << bookTitle << ": " << description;
}

bool Book::operator==(const Book& rhs)
{
    return (this->bookTitle == rhs.bookTitle && this->description == rhs.description);
}

bool Book::operator!=(const Book& rhs)
{
    return !(*this == rhs);
}

bool Book::operator<(const Book& rhs)
{
    if (this->price < rhs.price)
        return true;

    else if (this->price == rhs.price)
    {
        if (this->bookTitle < rhs.bookTitle)
            return true;
    }
    else
        return false;
}

bool Book::operator>(const Book& rhs)
{
    if (this->price > rhs.price)
        return true;

    else if (this->price == rhs.price)
    {
        if (this->bookTitle > rhs.bookTitle)
            return true;
    }
    else
        return false;
}

std::ostream& operator<<(std::ostream& outprint, const Book& book)
{
    /* Book book(...)
     * std::cout << book;
     */

    outprint << "Title: " << book.bookTitle << std::endl;
    outprint << "Price: " << book.price << std::endl;
    outprint << "Quantity: " << book.quantity << std::endl;
    outprint << "Description: " << book.description;

    return outprint;
}

std::istream& operator>>(std::istream& input, Book& book)
{
    /* Book book(...)
     * cin >> book;
     */

    getline(input, book.bookTitle);
    getline(input, book.description);
    input >> book.price;
    input >> book.quantity;

    return input;
}
