#include "engine.h"

Engine::Engine(int horsePower, int cubicCapacity) : horsePower(horsePower), cubicCapacity(cubicCapacity) {}

void Engine::SetHorsePower(int horsePower)
{
    this->horsePower = horsePower;
}

void Engine::SetCubicCapacity(int cubicCapacity)
{
    this->cubicCapacity = cubicCapacity;
}

int Engine::GetHorsePower() const
{
    return horsePower;
}

int Engine::GetCubicCapacity() const
{
    return cubicCapacity;
}