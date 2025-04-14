#include "cruiseship.h"
#include <iostream>

CruiseShip::CruiseShip(std::string name, std::string yearBuilt, int maxPassengers) : Ship(name, yearBuilt), maxPassengers(maxPassengers) {}

int CruiseShip::GetMaxPassengers() const
{
    return maxPassengers;
}

void CruiseShip::Print()
{
    Ship::Print();
    std::cout << "Maximum Passengers: " << maxPassengers << std::endl;
}

void CruiseShip::MakeItGo()
{
    std::cout << "The cruise ship goes woo woo!" << std::endl;
}
