#include "ship.h"
#include <iostream>

Ship::Ship(std::string name, std::string yearBuilt) : name(name), yearBuilt(yearBuilt) {}

std::string Ship::GetName() const
{
    return name;
}

std::string Ship::GetYearBuilt() const
{
    return yearBuilt;
}

void Ship::Print()
{
    std::cout << "Name: " << name << "\n" << "Year Built: " << yearBuilt << std::endl;
}
