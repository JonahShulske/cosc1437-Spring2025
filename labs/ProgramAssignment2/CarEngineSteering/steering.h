#ifndef _STEERING_H_
#define _STEERING_H_
#include <string>

class Steering
{
    private:
        std::string steeringType {};
        double wheelDiameter {};

    public:
        Steering(std::string steeringType, double wheelDiameter);

        // Setters
        void SetSteeringType(std::string steeringType);
        void SetWheelDiameter(double wheelDiameter);

        // Getters
        std::string GetSteeringType() const;
        double GetWheelDiameter() const;

        // Print function
        void Print() const;

};




#endif // _STEERING_H_
