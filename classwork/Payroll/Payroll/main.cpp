#include "employee.h"
#include "salaryemployee.h"
#include "hourlyemployee.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Globial variables
const int EMPID_LENGTH = 7;
const int FIRSTNAME_LENGTH = 12;
const int LASTNAME_LENGTH = 12;
const string EMPDATA_FILENAME = "employees.dat";
const string TIMEDATA_FILENAME = "emp_time.dat";
const string PAYROLL_REPORT_FILENAME = "payroll.txt";

struct EmployeeRecord   // 40 bytes total
{
    char employeeType;  // H for hourly, S for salary
    char id[EMPID_LENGTH];
    char firstName[FIRSTNAME_LENGTH];
    char lastName[LASTNAME_LENGTH];
    double salary;  // Weekly or hourly, depends on type.
};

struct EmployeeTime
{
    char id[EMPID_LENGTH];
    double hours;
};

// Function declarations
void LoadEmployees(vector<Employee*>& employees, string fileName);
void LoadEmployeeTime(vector<EmployeeTime>& empTime, string fileName);
void CreatePayrollReport(const vector<Employee*>& employees, const vector<EmployeeTime>& empTime, string fileName);
vector<Employee*>::const_iterator FindEmployee(const vector<Employee*>& employee, string id);

int main()
{
    vector<Employee*> employees;
    vector<EmployeeTime> timeCards;
    LoadEmployees(employees, EMPDATA_FILENAME);
    LoadEmployeeTime(timeCards, TIMEDATA_FILENAME);
    CreatePayrollReport(employees, timeCards, PAYROLL_REPORT_FILENAME);

    std::cout << "Done" << endl;
    return 0;
}

void LoadEmployees(vector<Employee*>& employees, string fileName)
{
    fstream file(fileName, ios::in | ios::binary);
    if (!file)
        throw runtime_error("Error: Could not open file");

    EmployeeRecord er;
    while (file.read(reinterpret_cast<char*>(&er), sizeof(er)))
    {
        if (er.employeeType == 'H' | er.employeeType == 'h')  // Hourly employee
            employees.push_back(new HourlyEmp(er.id, er.firstName, er.lastName, er.salary));
        else // Salary employee
            employees.push_back(new SalaryEmp(er.id, er.firstName, er.lastName, er.salary));
    }
    file.close();
}

void LoadEmployeeTime(vector<EmployeeTime>& empTime, string fileName)
{
    fstream file(fileName, ios::in | ios::binary);
    if (!file)
        throw runtime_error("Error: Could not open file");

    EmployeeTime et;
    while (file.read(reinterpret_cast<char*>(&et), sizeof(et)))
    {
        empTime.push_back(et);
    }
    file.close();
}

void CreatePayrollReport(const vector<Employee*>& employees, const vector<EmployeeTime>& empTime, string fileName)
{
}

vector<Employee*>::const_iterator FindEmployee(const vector<Employee*>& employee, string id)
{
    return vector<Employee*>::const_iterator();
}
