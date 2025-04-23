#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_
#include "employee.h"
#include <string>

class HourlyEmp : public Employee
{
    private:
        double hourlyWage;

    public:
        HourlyEmp(std::string empID, std::string firstName, std::string lastName, double hourlyWage);

        double CalculatePay(double hours = 0) override;
};

#endif // !_HOURLY_EMPLOYEE_H_
