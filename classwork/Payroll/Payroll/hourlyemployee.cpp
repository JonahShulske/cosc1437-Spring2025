#include "hourlyemployee.h"

HourlyEmp::HourlyEmp(std::string empID, std::string firstName, std::string lastName, double hourlyWage) : Employee(empID, firstName, lastName), hourlyWage(hourlyWage) {}

double HourlyEmp::CalculatePay(double hours)
{
    return (hours * hourlyWage);
}
