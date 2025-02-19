#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // Mix of functions used to work in library
#include <limits>       // Constants that give largest int, most bytes, etc.
#include <stdexcept>    // std exceptions
using namespace std;

// Global variables
const int CREATURE_NAME_SIZE = 30;
const int CREATURE_TYPE_SIZE = 26;
const string FILE_NAME = "creatures.dat";

struct Creature
{
    char Name[CREATURE_NAME_SIZE];  // C-String
    char creatureType[CREATURE_TYPE_SIZE];
    int HP;
    int Armor;
    int Speed;
};  // 68 bytes

// Prototypes
int GetCreatureNumber(int numCreatures);
void DisplayCreature(fstream& ogFile, int Num); // Always pass file as reference, never as a stream
void DisplaySorted(fstream& ogFile);
int AddCreature(fstream& ogFile, int numCreatures);
bool SortByName(const Creature& lhs, const Creature& rhs);   // Left hand side (lhs) and Right hand side (rhs)

 
  // seekg is for reading and takes 2 parameters, an offset and from_where. Safer??? file.seekg(0L, ios::end);
  // seekp is for writing.
  // tellg takes no parameters, from whereever the file cursor is, how many bytes from beginning of file. Add to tellp to get total # of bytes int size = file.tellg();
  // tellp takes no parameters, from whereever the file cursor is, how many bytes til end of file. Add to tellg to get total # of bytes

int main()
{
    char Choice;
    fstream creatureFile;
    // Flags. Binary is int value that tell program what mode to open file in. app makes sure data isnt truncted. in and out allow for reading and writing
    creatureFile.open(FILE_NAME, ios::in | ios::out | ios::app | ios::binary);

     // Get the current number of creatures in the file
    creatureFile.seekg(0L, ios::end);
    int numCreatures = (creatureFile.tellg() / sizeof(Creature));

    do
    {
        std::cout << "Menu" << endl;
        std::cout << "1. Display a Specific Creature\n" << "2. Display All Creatures Sorted By Name\n" << "3. Add a Creature\n" << "4. Quit" << endl;
        std::cout << "Enter Choice: ";
        cin >> Choice;

        // Clear/Burn the stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (Choice)
        {
            case '1': // Display a specific creature
                DisplayCreature(creatureFile, GetCreatureNumber(numCreatures));
                break;

            case '2': // Display a sorted creature
                DisplaySorted(creatureFile); 
                break;

            case '3': // Add a creature
                numCreatures = AddCreature(creatureFile, numCreatures);
                break;
            
            case '4': // Quit
                std::cout << "Quitter" << endl;
                break;

            default:
                std::cout << "Invaid option, try again" << endl;
                break;
        }

        if (Choice != '4')
        {
            // Pretty much only works on windows
            system("PAUSE");
            system("CLS");
        }
    } while (Choice != '4');

    creatureFile.close();

    return 0;
}

int GetCreatureNumber(int numCreatures)
{
    return 0;
}

void DisplayCreature(fstream& ogFile, int Num)
{
}

void DisplaySorted(fstream& ogFile)
{
}

int AddCreature(fstream& ogFile, int numCreatures)
{
    return 0;
}

bool SortByName(const Creature& lhs, const Creature & rhs)
{
    return false;
}
