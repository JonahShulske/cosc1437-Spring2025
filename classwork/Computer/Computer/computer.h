#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <string>
#include "cpu.h"
#include "monitor.h"

class Computer
{
    private:
        std::string id {};
        std::string brand {};
        std::string model {};
        CPU cpu;
        Monitor monitor;

    public:
        Computer(std::string id, std::string brand, std::string model, const CPU& cpu, const Monitor& monitor);

        // Getters
        std::string GetID() const;
        std::string GetBrand() const;
        std::string GetModel() const;

        CPU GetCPU() const;
        void SetCPU(const CPU& cpu);

        Monitor GetMonitor() const;
        void SetMonitor(const Monitor& monitor);

        void Print() const;
};

#endif
