#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "car.h"
using namespace std;

void AddCar(vector<Car>& cars);
bool DeleteCar(vector<Car>& cars);
bool UpdateCarCondition(vector<Car>& cars);
void DisplayCar(const vector<Car>& cars);
void DisplayAllCars(const vector<Car>& cars);
bool RentCar(vector<Car>& cars);
bool ReturnCar(vector<Car>& cars);

int main()
{
    char input;
    do
    {
        std::cout << "CAR RENTAL AGENCY MENU" << endl;
        std::cout << "a - Add car to inventory\n" << "d - delete car from inventory" << endl;
        std::cout << "u - Update car by id condition in inventory\n" << "s - Display one car by id from inventory" << endl;
        std::cout << "i - Display list of all cars in inventory\n" << "c - Rent a car by id in inventory" << endl;
        std::cout << "r -Return a car by id to inventory\n" << "q - Quit" << endl;
        std::cout << "Choose an option: " << endl;
        cin >> input;
        cout << endl;

            switch (input)
            {
                /*case 'A':
                case 'a': AddCar(); break;*/

                /*
                case 'D':
                case 'd': DeleteCar(); break;

                case 'U':
                case 'u': UpdateCarCondition(); break;

                case 'S':
                case 's': DisplayCar(); break;

                case 'I':
                case 'i': DisplayAllCars(); break;

                case 'C':
                case 'c': RentCar(); break;

                case 'R':
                case 'r': ReturnCar(); break;

                case 'Q':
                case 'q': Quit(); break;
                */
            }
    } while (input != 'q' && input != 'Q');
    cin.ignore();
}


void AddCar(vector<Car>& cars)
{
}

bool DeleteCar(vector<Car>&cars)
{
    return false;
}

bool UpdateCarCondition(vector<Car>& cars)
{
    return false;
}

void DisplayCar(const vector<Car>& cars)
{}

void DisplayAllCars(const vector<Car>&cars)
{}

bool RentCar(vector<Car>&cars)
{
    return false;
}

bool ReturnCar(vector<Car>& cars)
{
    return false;
}

void Quit()
{}
