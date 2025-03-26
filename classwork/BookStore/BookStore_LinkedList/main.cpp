#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include "book.h"
#include "bookbag.h"

using namespace std;

void PrintBookBag(BookBag& bag)
{
    for (int index = 0; index < bag.GetUniqueBookCount(); ++index)
        std::cout << bag[index] << endl;
}

int main()
{
    string fileName = "book_list.txt";
    BookBag myBag("Jonah Shulske", " 8/21/05");

    // Open file
    ifstream file(fileName);
    if (!file)
    {
        std::cout << "Could not open file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    Book book;
    while (file >> book)
    {
        file.ignore();  // Remove newline at end of stream
        myBag.AddBook(book);
    }

    // Output each book

    PrintBookBag(myBag);
    std::cout << "\n" << string(20, '-') << "\n" << endl;
    //std::cout << "\n-------------------------------\n";
    std::cout << myBag << endl;


    return 0;
}