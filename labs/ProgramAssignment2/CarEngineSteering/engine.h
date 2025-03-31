#ifndef _ENGINE_H_
#define _ENGINE_H_
#include "car.h"

class Engine
{
    private:
        int horsePower;
        int cubicCapacity;

    public:
        // Constructor
        Engine(int horsePower, int cubicCapacity) : horsePower(horsePower), cubicCapacity(cubicCapacity) {}

        // Setters
        void SetHorsePower(int horsePower) { this->horsePower = horsePower; }
        void SetCubicCapacity(int cubicCapacity) { this->cubicCapacity = cubicCapacity; }

        // Getters
        int GetHorsePower() const { return horsePower; }
        int GetCubicCapacity() const { return cubicCapacity; }
        // Print function

        void Print() const {
        std::cout << "Horse Power: " << horsePower << ", Cubic Capacity: " << cubicCapacity << "cc" << std::endl;
        };

};
#endif // !_ENGINE_H_

