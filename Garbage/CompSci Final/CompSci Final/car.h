#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>

class Car
{
    private:
        int id;
        std::string make;
        std::string model;
        int year;
        std::string condition;
        bool rented;

    public:
        Car(int id, std::string make, std::string model, int year, std::string condition, bool rented);

        int GetID() const;
        std::string GetMake() const;
        std::string GetModel() const;
        int GetYear() const;
        std::string GetCondition() const;
        bool IsRented() const;

        void SetCondition(std::string condition);
        void ToggleRented(bool rented);

        void DisplayCar() const;


};



#endif  // !_CAR_H_
