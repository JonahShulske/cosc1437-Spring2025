#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <string>
#include "steering.h"
#include "engine.h"

class Car
{
    private:
        std::string id {};
        std::string make {};
        std::string model {};
        Steering steering;
        Engine engine;

    public:
        Car(std::string id, std::string make, std::string model, const Engine& engine, const Steering& steering);

        // Getters
        std::string GetID() const;
        std::string GetMake() const;
        std::string GetModel() const;
        Steering GetSteering() const;
        Engine GetEngine() const;

        //// Setters
        void SetSteering(const Steering& steering);
        void SetEngine(const Engine& engine);

        // Print Functions
        void Print() const;

};
#endif // _CAR_H_
