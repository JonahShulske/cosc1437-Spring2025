#ifndef _CARGO_SHIP_H_
#define _CARGO_SHIP_H_

#include <string>
#include "ship.h"

class CargoShip : public Ship
{
    private:
        int tonnage;

    public:
        // Constructor
        CargoShip(std::string name, std::string yearBuilt, int tonnage);

        // Getter
        int GetTonnage() const;

        // Print method
        void Print() override;  // Override keyword technically not required, but it works as a check for the programmer.
        void MakeItGo() override;
};


#endif // !_CARGO_SHIP_H_
