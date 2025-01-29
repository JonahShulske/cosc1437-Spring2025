// Headers
#include <iostream> // cin, cout
#include <string>
#include <vector> // Vectors
#include <fstream> // ifstream and ofstream
#include <iomanip> // Format output
#include <stdexcept> // Can throw exceptions

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
    vector<Person> myPeople;

    // Open and process file, stores in myPeople
    ReadFile(myPeople, FILE_NAME_IN);

    // Display to the monitor
    std::cout << "Unsorted File" << endl;
    DisplayVector(myPeople);
    cout << "\n" << endl;

    // Sort by Last Name
    std::cout << "Sort by last name" << endl;
    SortVector(myPeople, 0);    // 0 is for Last Name
    DisplayVector(myPeople);
    cout << "\n" << endl;

    // Sort by Age
    std::cout << "Sort by age" << endl;
    SortVector(myPeople, 1); // 1 is for Age
    DisplayVector(myPeople);
    cout << "\n" << endl;

    // Write out the Vector sorted by Age
    WriteFile(myPeople, FILE_NAME_OUT);
    return 0;
}

void ReadFile(vector<Person>& People, string fileName)
{
    // Open the file
    /* ifstream ogFile;
     * ogFile.open(fileName); 
     */ 

    ifstream ogFile(fileName);

    // Check if the file is open
    if (!ogFile)
    {
        // File isn't open
        throw runtime_error("Could not open file: " + fileName);
    }

    string firstName;
    string lastName;
    int Age;

    // Iterate over the file
    while (ogFile >> firstName)
    {
        ogFile >> lastName;
        ogFile >> Age;

        People.push_back(Person {firstName, lastName, Age});    // Created anonymous person
    };

    ogFile.close();
}

void WriteFile(const vector<Person>& People, string fileName)
{
    ofstream newFile(fileName);

    if (!newFile)
    {
        throw runtime_error("Could not open file: " + fileName);
    }

    for (int index = 0; index < People.size(); ++index)
    {
        newFile << People.at(index).firstName << " " << People.at(index).lastName << " " << People.at(index).Age << endl;
    }
    newFile.close(); // Written as a sort by age
}

void SortVector(vector<Person>& People, int sortType)
{
    // Bubble Sort
    // Outer for loop controls when to stop looping

    for (int index = People.size() - 1; index > 0; --index)
    {
        // Inner for loop controls the number of elements to loop over each time

        for (int index2 = 0; index2 < index; ++index2)
        {
            // Test if element index2 and element index2 + 1 are not in the correct order. Swap if they aren't

            switch (sortType)
            {
                case 0: // Sort by Last Name
                {
                    if (!SortByName(People.at(index2).lastName, People.at(index2 + 1).lastName))
                    {
                        swap(People.at(index2).lastName, People.at(index2 + 1).lastName);
                    }

                    break;
                }

                case 1: // Sort by Age
                {
                    if (!SortByAge(People.at(index2).Age, People.at(index2 + 1).Age))
                    {
                        swap(People.at(index2), People.at(index2 + 1));
                    }

                    break;
                }
                default:
                    throw runtime_error("How did you even get here lmao");
            }
        }
    }

}

bool SortByAge(int a, int b)
{
    // Ascending sort
    return a <= b;
}

bool SortByName(string a, string b)
{
    // Ascending sort
    return a <= b;
}

void Swap(Person & p1, Person & p2)
{
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

void DisplayVector(const vector<Person>& People)
{
    // Output a table header
    std::cout << setw(15) << left << "Last Name" << setw(15) << "First Name" << setw(4) << right << "Age" << endl;

    // Output table body
    for (int index = 0; index < People.size(); ++index)
    {
        std::cout << setw(15) << left << People.at(index).lastName << setw(15) << People.at(index).firstName << setw(4) << right << People.at(index).Age << endl;
    };
}
