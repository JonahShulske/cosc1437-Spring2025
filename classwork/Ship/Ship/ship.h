#ifndef _SHIP_H_
#define _SHIP_H_
#include <string>

class Ship
{
    private:
        std::string name;
        std::string yearBuilt;

    public:
        // Constructor
        Ship(std::string name, std::string yearBuilt);

        // Getters
        std::string GetName() const;
        std::string GetYearBuilt() const;

        // Print function
        virtual void Print();

        // Pure virtual function
        virtual void MakeItGo() = 0;
};


#endif // !_SHIP_H_
