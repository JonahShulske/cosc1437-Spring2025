#include "car.h"
#include "engine.h"
#include "steering.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Car::Car(string id, string make, string model, const Steering& steering, const Engine& engine) : id(id), make(make), model(model), steering(steering), engine(engine) {}

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
    return Steering();
}

Engine Car::GetEngine() const
{
    return Engine();
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
{}
