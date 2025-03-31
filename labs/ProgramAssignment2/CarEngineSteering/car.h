#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

class Car
{
private:
    std::string id {};
    std::string make {};
    std::string model {};
    std::string steeringType {};
    int horsePower {};
    int cubicCapacity {};
    int wheelDiameter {};

    public:
        Car(std::string id, std::string make, std::string model, std::string steeringtype, int horsePower, int cubicCapacity, double wheelDiameter);

        // Getters
        std::string GetID(std::string id) const;
        std::string GetMake(std::string make) const;
        std::string GetModel(std::string model) const;
        std::string GetSteeringType(std::string steeringType) const;
        // Setters


        // Print Functions
        void Print() const;
};


#endif // _CAR_H_
