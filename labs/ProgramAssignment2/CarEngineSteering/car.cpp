#include "car.h"
#include "engine.h"
#include "steering.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Car::Car(string id, string make, string model, const Engine& engine, const Steering& steering) : id(id), make(make), model(model), engine(engine), steering(steering) {}

// Getters

std::string Car::GetID() const
{
    return id;
}

std::string Car::GetMake() const
{
    return std::string();
}

std::string Car::GetModel() const
{
    return std::string();
}

Steering Car::GetSteering() const
{
    return steering;
}

Engine Car::GetEngine() const
{
    return engine;
}

void Car::SetSteering(const Steering &steering)
{
    this->steering = steering;
}

void Car::SetEngine(const Engine & engine)
{
    this->engine = engine;
}

void Car::Print() const
{
    std::cout << "Car: " << id << " " << make << " " << model << endl;
    std::cout << "\t Horsepower: " << engine.GetHorsePower() << endl;
    std::cout << "\t Cubic Capacity: " << engine.GetCubicCapacity() << endl;
    std::cout << "\t Steering Type: " << steering.GetSteeringType() << endl;
    std::cout << "\t Wheel Diameter: " << steering.GetWheelDiameter() << endl;

    cout << endl;
}
