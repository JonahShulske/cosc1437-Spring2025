#include "monitor.h"
#include <iostream>
#include <stdexcept>

Monitor::Monitor(std::string resolution, double size) : resolution(resolution), size(size)
{
}

std::string Monitor::GetResolution() const
{
    return resolution;
}

void Monitor::SetResolution(std::string resolution)
{
    /*if (resolution.size() <= 0)
        throw std::runtime_error("Error: Resolution Must be Above 0");*/

    if (resolution != "1080p" && resolution != "1440p" && resolution != "2160p")
        throw std::runtime_error("Error: Unsupported Resolution. Use 1080p, 1440p, or 2160p");
    this->resolution = resolution;
}

double Monitor::GetSize() const
{
    return size;
}

void Monitor::SetSize(double size)
{
    if (size <= 0)
        throw std::runtime_error("Error: Size Must Be Above 0");
    this->size = size;
}

void Monitor::Print() const
{
    std::cout << "\tMonitor Resolution: " << resolution << std::endl;
    std::cout << "\tMonitor Size: " << size << " inches" << std::endl;
}
