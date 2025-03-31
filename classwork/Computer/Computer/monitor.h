#ifndef _MONITOR_H_
#define _MONITOR_H_

#include <string>

class Monitor
{
    private:
        std::string resolution {};
        double size {};

    public:
        Monitor(std::string resolution, double size);

        std::string GetResolution() const;
        void SetResolution(std::string resolution);
        
        double GetSize() const;
        void SetSize(double size);

        void Print() const;
};

#endif _MONITOR_H_
