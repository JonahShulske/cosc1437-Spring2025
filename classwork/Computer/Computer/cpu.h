#ifndef _CPU_H_
#define _CPU_H_

class CPU
{
    private:
        int cores {};
        double clockSpeed {};  // In GHz

    public:
        CPU(int cores, double clockSpeed);

        int GetCores() const;
        void SetCores(int cores);
        
        int GetClockSpeed() const;
        int SetClockSpeed(int clockSpeed);

        void Print() const;
       
};

#endif _CPU_H_