#include "cruiseship.h"

CruiseShip::CruiseShip(std::string name, std::string yearBuilt, int maxPassengers) : Ship(name, yearBuilt), maxPassengers(maxPassengers) {}

int CruiseShip::GetMaxPassengers() const
{
    return maxPassengers;
}

void CruiseShip::Print()
{
    Ship::Print();
}

void CruiseShip::MakeItGo()
{
}
