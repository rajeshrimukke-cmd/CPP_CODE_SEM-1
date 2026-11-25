#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int empId;
    string name;
    float baseSalary;
public:
    Employee(int id = 0, string n = "Unknown", float salary = 0) {
        empId = id;
        name = n;
        baseSalary = salary;
    }

    void setBaseSalary(float salary) {
        this->baseSalary = salary;
    }

    Employee& setEmpId(int id) {
        this->empId = id;
        return *this;
    }

    Employee& setName(string n) {
        this->name = n;
        return *this;
    }

    virtual float calculateSalary() = 0;
    virtual void displayInfo() = 0;
    virtual ~Employee() {}
};

class PermanentEmployee : public Employee {
private:
    float bonus;
    float allowances;
public:
    PermanentEmployee(int id = 0, string n = "Unknown", float salary = 0, float b = 0, float a = 0)
        : Employee(id, n, salary) {
        bonus = b;
        allowances = a;
    }

    float calculateSalary() override {
        return baseSalary + bonus + allowances;
    }

    void displayInfo() override {
        cout << "--- Permanent Employee ---" << endl;
        cout << "ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Base Salary: " << baseSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Allowances: " << allowances << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

class ContractEmployee : public Employee {
private:
    int contractDuration;
    float hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(int id, string n, float salary, int duration, float rate, int hours)
        : Employee(id, n, salary) {
        contractDuration = duration;
        hourlyRate = rate;
        hoursWorked = hours;
    }

    float calculateSalary() override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() override {
        cout << "--- Contract Employee ---" << endl;
        cout << "ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Contract Duration: " << contractDuration << " months" << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: " << calculateSalary() << endl;
    }
};

void demonstratePointers() {
    cout << "\n=== Pointers to Objects ===" << endl;
    PermanentEmployee emp1(101, "John Doe", 50000, 10000, 5000);
    ContractEmployee emp2(102, "Jane Smith", 0, 6, 200, 160);

    PermanentEmployee *ptr1 = &emp1;
    ptr1->displayInfo();

    Employee *employees[2];
    employees[0] = new PermanentEmployee(103, "Bob Johnson", 60000, 15000, 7000);
    employees[1] = new ContractEmployee(104, "Alice Brown", 0, 3, 250, 150);

    for (int i = 0; i < 2; i++) {
        employees[i]->displayInfo();
        delete employees[i];
    }
}

void demonstrateThisPointer() {
    cout << "\n=== this Pointer and Method Chaining ===" << endl;
    PermanentEmployee emp;
    emp.setEmpId(105)
       .setName("Charlie Wilson")
       .setBaseSalary(45000);
    emp.displayInfo();
}

int main() {
    PermanentEmployee perm(1001, "David Miller", 55000, 12000, 6000);
    ContractEmployee contract(1002, "Sarah Davis", 0, 4, 180, 160);
    
    perm.displayInfo();
    cout << endl;
    contract.displayInfo();
    
    demonstratePointers();
    demonstrateThisPointer();
    
    return 0;
}