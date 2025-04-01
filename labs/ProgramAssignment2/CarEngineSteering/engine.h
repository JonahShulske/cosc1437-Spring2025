#ifndef _ENGINE_H_
#define _ENGINE_H_
#include "car.h"

class Engine
{
    private:
        int horsePower {};
        int cubicCapacity {};

    public:
        // Setters
        void SetHorsePower(int horsePower) { this->horsePower = horsePower; }
        void SetCubicCapacity(int cubicCapacity) { this->cubicCapacity = cubicCapacity; }

        // Getters
        int GetHorsePower() const { return horsePower; }
        int GetCubicCapacity() const { return cubicCapacity; }
        // Print function

        void Print() const {
        };

};
#endif // !_ENGINE_H_

