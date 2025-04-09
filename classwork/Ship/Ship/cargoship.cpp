#include "cargoship.h"
#include <iostream>

CargoShip::CargoShip(std::string name, std::string yearBuilt, int tonnage) : Ship(name, yearBuilt), tonnage(tonnage) {}

int CargoShip::GetTonnage() const
{
    return tonnage;
}

void CargoShip::Print()
{
    Ship::Print();
    std::cout << "Cargo Capacity: " << tonnage << " tons" << std::endl;
}

void CargoShip::MakeItGo()
{
    std::cout << "The cargo ship goes toot toot!" << std::endl;
}
