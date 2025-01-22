// Headers
#include <iostream> // cin, cout
#include <string>
#include <vector> // Vectors
#include <fstream> // ifstream and ofstream
#include <iomanip> // Format output
#include <stdexcept> // Can throw exceptions
#include "main.h"

using namespace std;

// Global Variables (declared outside any function)
const string FILE_NAME_IN = "people.txt";
const string FILE_NAME_OUT = "people_sorted.txt";

// struct - ADT Wrapper (Abstract Data Type) for PODS (Plain Old Data)
/* Vector - Container.Can only contain one type of data
 * When passing object, you wanna do it by reference 
 */

struct Person
{
    string firstName;
    string lastName;
    int Age;
};

// Prototypes
void ReadFile(vector<Person>& People, string fileName);
void WriteFile(const vector<Person>& People, string fileName);
void SortVector(vector<Person>& People, int sortType);
bool SortByAge(int a, int b);
bool SortByName(string a, string b);
void Swap(Person& p1, Person& p2);
void DisplayVector(const vector<Person>& People);

int main()
{

}

void ReadFile(vector<Person>& People, string fileName)
{

}

void WriteFile(const vector<Person>& People, string fileName)
{

}

void SortVector(vector<Person>& People, int sortType)
{

}

bool SortByAge(int a, int b)
{
    return false;
}

bool SortByName(string a, string b)
{
    return false;
}

void Swap(Person & p1, Person & p2)
{

}

void DisplayVector(const vector<Person>& People)
{

}
