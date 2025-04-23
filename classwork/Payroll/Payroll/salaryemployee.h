#ifndef _SALARY_EMPLOYEE_H_
#define _SALARY_EMPLOYEE_H_
#include "employee.h"
#include <string>

class SalaryEmp : public Employee
{
    private:
        double weeklySalary;

    public:
        SalaryEmp(std::string empID, std::string firstName, std::string lastName, double weeklySalary);

        double CalculatePay(double hours = 0) override;
};

#endif // !_SALARY_EMPLOYEE_H_