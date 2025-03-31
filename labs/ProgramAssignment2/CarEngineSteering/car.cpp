#include "car.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Car::Car(string id, string make, string model, string steeringType, int horsePower, int cubicCapacity, double wheelDiameter) : id(id), make(make), model(model), steeringType(steeringType), horsePower(horsePower), cubicCapacity(cubicCapacity), wheelDiameter(wheelDiameter) {}

std::string Car::GetID(std::string id) const
{
    return std::string();
}

std::string Car::GetMake(std::string make) const
{
    return std::string();
}

std::string Car::GetModel(std::string model) const
{
    return std::string();
}

std::string Car::GetSteeringType(std::string steeringType) const
{
    return std::string();
}

void Print()
{
}

// Getters

