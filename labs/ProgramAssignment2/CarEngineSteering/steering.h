#ifndef _STEERING_H_
#define _STEERING_H_
#include "car.h"

class Steering
{
    private:
        std::string steeringType;
        double wheelDiameter;

    public:
        // Constructor
        Steering(std::string steeringType, double wheelDiameter) : steeringType(steeringType), wheelDiameter(wheelDiameter) {}

        // Setters
        void SetSteeringType(std::string steeringType) { this->steeringType = steeringType; }
        void SetWheelDiameter(double wheelDiameter) { this->wheelDiameter = wheelDiameter; }

        // Getters
        std::string GetSteeringType() const { return steeringType; }
        double GetWheelDiameter() const { return wheelDiameter; }

        // Print function
        void Print() const {
            std::cout << "Steering Type: " << steeringType << ", Wheel Diameter: " << wheelDiameter << " inches" << std::endl;
        };

};




#endif // _STEERING_H_
