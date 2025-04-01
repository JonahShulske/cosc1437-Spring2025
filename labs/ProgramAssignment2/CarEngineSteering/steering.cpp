#include "steering.h"
#include <iostream>
#include <string>
using namespace std;

Steering::Steering(string steeringType, double wheelDiameter) : steeringType(steeringType), wheelDiameter(wheelDiameter) {}

void Steering::SetSteeringType(std::string steeringType)
{
    this->steeringType = steeringType;
}

void Steering::SetWheelDiameter(double wheelDiameter)
{
    this->wheelDiameter = wheelDiameter;
}

std::string Steering::GetSteeringType() const
{
    return steeringType;
}

double Steering::GetWheelDiameter() const
{
    return wheelDiameter;
}

void Steering::Print() const
{

}

