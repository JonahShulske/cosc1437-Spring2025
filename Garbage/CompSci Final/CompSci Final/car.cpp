#include "car.h"
using namespace std;

Car::Car(int id, string make, string model, int year, string condition, bool rented)
    : id(id), make(make), model(model), year(year), condition(condition), rented(rented) {}

int Car::GetID() const
{
    return id;
}

string Car::GetMake() const
{
    return make;
}

string Car::GetModel() const
{
    return model;
}

int Car::GetYear() const
{
    return year;
}

string Car::GetCondition() const
{
    return condition;
}

bool Car::IsRented() const
{
    return false;
}

void Car::SetCondition(string condition)
{
    this->condition = condition;
}

void Car::ToggleRented(bool rented)
{
    this->rented = rented;
}

void Car::DisplayCar() const
{
    std::cout << "ID: " << id << "Make: " << make << endl;
    std::cout << "Mode: " << model << "Year: " << year << endl;
    std::cout << "Condition: " << condition << "Rented: " << (rented ? "is available" : "is not available") << endl;
}
