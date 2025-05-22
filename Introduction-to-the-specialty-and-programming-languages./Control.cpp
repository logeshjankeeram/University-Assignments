#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Department;

class Employee
{
protected:
    string name;
    int age;
    double baseSalary;
    bool isEmployed;
    Department *department;

public:
    Employee(string n, int a, double s, Department *dept = nullptr)
        : name(n), age(a), baseSalary(s), isEmployed(true), department(dept) {}
    virtual double calculatePay() const = 0;
    virtual ~Employee() {}

    void printInfo() const
    {
        cout << "Name:" << name << ", Age:" << age << ", Salary:" << baseSalary
             << ", status:" << (isEmployed ? "Employed" : "Fired")
             << ", Department:" << (department ? department->getName() : "None") << endl;
    }

    void fire()
    {
        isEmployed = false;
    }

    string getName() const
    {
        return name;
    }

    bool isStillEmployed() const
    {
        return isEmployed;
    }

    Department *getDepartment() const
    {
        return department;
    }

    friend class HR;
};

class Department
{
private:
    string departmentName;
    vector<Employee *> employees;

public:
    Department(string name) : departmentName(name) {}
    ~Department() {}

    void addEmployee(Employee *e)
    {
        employees.push_back(e);
    }

    void removeEmployee(Employee *e)
    {
        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
            if (*it == e)
            {
                employees.erase(it);
                break;
            }
        }
    }

    string getName() const
    {
        return departmentName;
    }

    void displayAll() const
    {
        cout << "Department: " << departmentName << endl;
        cout << "Employees:" << endl;
        for (const auto &emp : employees)
        {
            emp->printInfo();
            cout << "Total Pay:" << emp->calculatePay() << endl;
        }
    }

    static void fireThisPerson(Employee &emp)
    {
        emp.fire();
    }

    int countEmployees(bool employedOnly = false) const
    {
        if (!employedOnly)
            return employees.size();
        int count = 0;
        for (const auto &emp : employees)
        {
            if (emp->isStillEmployed())
                count++;
        }
        return count;
    }
};

class HR
{
public:
    static void assignToDepartment(Employee *emp, Department *newDept)
    {
        if (emp->department)
        {
            emp->department->removeEmployee(emp);
        }
        emp->department = newDept;
        newDept->addEmployee(emp);
    }

    static void transferEmployee(Employee *emp, Department *fromDept, Department *toDept)
    {
        fromDept->removeEmployee(emp);
        toDept->addEmployee(emp);
        emp->department = toDept;
    }
};

class Manager : public Employee
{
private:
    int bonusPercentage;

public:
    Manager(string n, int a, double s, int b, Department *dept = nullptr)
        : Employee(n, a, s, dept), bonusPercentage(b) {}
    ~Manager() {}

    double calculatePay() const override
    {
        return baseSalary + (baseSalary * bonusPercentage / 100);
    }
};

class SalesPerson : public Employee
{
private:
    int numberOfSales;
    double commissionPerSale;

public:
    SalesPerson(string n, int a, double s, int sales, double comm, Department *dept = nullptr)
        : Employee(n, a, s, dept), numberOfSales(sales), commissionPerSale(comm) {}
    ~SalesPerson() {}

    double calculatePay() const override
    {
        return baseSalary + (numberOfSales * commissionPerSale);
    }
};

int main()
{
    Department finance("Finance");
    Department sales("Sales");
    Department marketing("Marketing");

    Manager *alice = new Manager("Alice", 42, 4500, 20);
    SalesPerson *bob = new SalesPerson("Bob", 29, 2800, 10, 120);
    Manager *charlie = new Manager("Charlie", 35, 5000, 15);
    SalesPerson *dave = new SalesPerson("Dave", 30, 3000, 5, 150);

    HR::assignToDepartment(alice, &finance);
    HR::assignToDepartment(bob, &sales);
    HR::assignToDepartment(charlie, &marketing);

    cout << "Initial Employee information:" << endl;
    finance.displayAll();
    sales.displayAll();
    marketing.displayAll();

    cout << "Transferring Bob to Finance:" << endl;
    HR::transferEmployee(bob, &sales, &finance);
    cout << "After transfer:" << endl;
    finance.displayAll();
    sales.displayAll();

    Department::fireThisPerson(*alice);

    cout << "After firing Alice:" << endl;
    finance.displayAll();

    cout << "Number of employees in Finance:" << finance.countEmployees(false) << endl;
    cout << "Number of employed in Finance:" << finance.countEmployees(true) << endl;

    delete alice;
    delete bob;
    delete charlie;
    delete dave;

    return 0;
}