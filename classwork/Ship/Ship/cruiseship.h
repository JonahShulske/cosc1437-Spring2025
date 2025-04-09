#ifndef _CRUISE_SHIP_H_
#define _CRUISE_SHIP_H_
#include <string>
#include "ship.h"

class CruiseShip : public Ship
{
    private:
        int maxPassengers;

    public:
        // Constructor
        CruiseShip(std::string name, std::string yearBuilt, int maxPassengers);

        // Getter
        int GetMaxPassengers() const;

        // Print/Overridden Functions
        void Print() override;
        void MakeItGo() override;
};



#endif // !_CRUISE_SHIP_H_