#include "salaryemployee.h"

SalaryEmp::SalaryEmp(std::string empID, std::string firstName, std::string lastName, double weeklySalary) : Employee(empID, firstName, lastName), weeklySalary(weeklySalary) {}

double SalaryEmp::CalculatePay(double hours)
{
    return weeklySalary;
}
