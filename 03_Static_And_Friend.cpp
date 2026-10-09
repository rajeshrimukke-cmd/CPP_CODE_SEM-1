#include <iostream>
#include <string>
using namespace std;

class StaticExample {
private:
    static int count;
    int id;

public:
    StaticExample() {
        count++;
        id = count;
    }

    static void showCount() {
        cout << "Total objects created: " << count << endl;
    }

    void display() const {
        cout << "Object ID: " << id << endl;
    }
};

int StaticExample::count = 0;

class ClassA;
class ClassB;

class ClassA {
private:
    int valueA;

public:
    ClassA(int v) : valueA(v) {}

    friend void compareValues(ClassA &a, ClassB &b);
};
