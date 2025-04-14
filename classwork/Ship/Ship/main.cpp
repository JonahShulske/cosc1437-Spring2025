#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ship.h"
#include "cargoship.h"
#include "cruiseship.h"
using namespace std;

const int NAME_LENGTH = 30;
const int YEAR_LENGTH = 5;
const string FILE_NAME = "ship.dat";

struct ShipRecord
{
    char shipType;  // C for Cargo, L for Cruise
    char shipName[NAME_LENGTH];
    char shipYear[YEAR_LENGTH];
    int data;     // Passengers and tonnage
};

void LoadShips(vector<Ship*>& vShip, string fileName);

int main()
{
    vector<Ship*> ships;
    LoadShips(ships, FILE_NAME);

    // Print out ships
    for (Ship* s : ships)
    {
        s->MakeItGo();
        cout << endl;
        s->Print();
        cout << endl;
    }


    return 0;
}

void LoadShips(vector<Ship*>& vShip, string fileName)
{
    // Opening a file for writing
    ofstream outFile("ships.txt");

    // Opening a file for reading
    fstream inFile(fileName, ios::in | ios::binary);
    if (!inFile)
    {
        std::cout << "ERROR: Could not open file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    ShipRecord sr;  // Temp holding for a ShipRecord
    while (inFile.read(reinterpret_cast<char*>(&sr), sizeof(sr)))
    {
        if (sr.shipType == 'L' || sr.shipType == 'l')   // Cruise Ship
            vShip.push_back(new CruiseShip(sr.shipName, sr.shipYear, sr.data));

        else    // Cargo Ship
            vShip.push_back(new CargoShip(sr.shipName, sr.shipYear, sr.data));

        outFile << sr.shipType << "," << sr.shipName << "," << sr.shipYear << "," << sr.data << endl;

    }
    inFile.close();
    outFile.close();
}
