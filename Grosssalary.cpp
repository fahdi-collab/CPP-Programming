#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id, hourwork, overtimehour;
    float wage, regularpay, overtimepay, grosssalary, bonus, finalsalary;

    cout << "Enter Your Name: ";
    getline(cin, name);

    cout << "Enter Your ID: ";
    cin >> id;

    cout << "Enter Your Hours Worked: ";
    cin >> hourwork;

    cout << "Enter Your Wage: ";
    cin >> wage;

    if (hourwork <= 40)
    {
        regularpay = hourwork * wage;
        overtimepay = 0;
        grosssalary = regularpay;
    }
    else
    {
        overtimehour = hourwork - 40;

        regularpay = 40 * wage;
        overtimepay = overtimehour * wage * 1.5;
        grosssalary = regularpay + overtimepay;
    }

    
    if (grosssalary < 10000)
    {
        bonus = 0;
    }
    else if (grosssalary <= 20000)
    {
        bonus = 0.05 * grosssalary;
    }
    else
    {
        bonus = 0.10 * grosssalary;
    }

    finalsalary = grosssalary + bonus;

    
    cout << "\n========== SALARY DETAILS ==========" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Regular Pay: Rs. " << regularpay << endl;
    cout << "Overtime Pay: Rs. " << overtimepay << endl;
    cout << "Gross Salary: Rs. " << grosssalary << endl;
    cout << "Bonus: Rs. " << bonus << endl;
    cout << "Final Salary: Rs. " << finalsalary << endl;
    cout << "====================================" << endl;

    return 0;
}
