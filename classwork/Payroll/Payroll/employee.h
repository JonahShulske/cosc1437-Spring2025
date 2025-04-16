#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee
{
    private:
        std::string empID;
        std::string firstName;
        std::string lastName;

    public:
        Employee(std::string empID, std::string firstName, std::string lastName);
        
        std::string GetEmpID() const;
        std::string GetFirstName() const;
        std::string GetLastName() const;

        bool operator==(const Employee& rhs) const;
        bool operator<(const Employee& rhs) const;

        virtual double CalculatePay(double hours = 0) = 0;
};

#endif // !_EMPLOYEE_H_