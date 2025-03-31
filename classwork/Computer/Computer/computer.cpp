#include "computer.h"
#include <iostream>

Computer::Computer(std::string id, std::string brand, std::string model, const CPU & cpu, const Monitor& monitor) : id(id), brand(brand), model(model), cpu(cpu), monitor(monitor)
{
}

std::string Computer::GetID() const
{
    return id;
}

std::string Computer::GetBrand() const
{
    return brand;
}

std::string Computer::GetModel() const
{
    return model;
}

CPU Computer::GetCPU() const
{
    return cpu;
}

void Computer::SetCPU(const CPU & cpu)
{
    this->cpu = cpu;
}

Monitor Computer::GetMonitor() const
{
    return monitor;
}

void Computer::SetMonitor(const Monitor & monitor)
{
    this->monitor = monitor;
}

void Computer::Print() const
{
    std::cout<< "Computer: " << id << " " << brand << " " << model << std::endl;

    cpu.Print();
    monitor.Print();
    std::cout << "\n" << std::endl;
}
