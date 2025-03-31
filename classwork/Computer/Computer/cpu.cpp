#include "cpu.h"
#include <iostream>
#include <stdexcept>

CPU::CPU(int cores, double clockSpeed) : cores(cores), clockSpeed(clockSpeed) {}

int CPU::GetCores() const
{
    return cores;
}

void CPU::SetCores(int cores)
{
    if (cores <= 0)
        throw std::invalid_argument("Error: Number of Cores Must be Above 0");

    this->cores = cores;
}

int CPU::GetClockSpeed() const
{
    return clockSpeed;
}

int CPU::SetClockSpeed(int clockSpeed)
{
    if (clockSpeed <= 0)
        throw std::invalid_argument("Error: Clock Speed Must be Above 0");

    this->clockSpeed = clockSpeed;
}

void CPU::Print() const
{
    std::cout << "\tCPU Cores: " << cores << std::endl;
    std::cout << "\tClock Speed: " << clockSpeed << "GHz" << std::endl;
}
