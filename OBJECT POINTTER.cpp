#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // Constructor
    Student(string n, int a) : name(n), age(a) {}

    // Member function to display details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Create an object dynamically using a pointer
    Student* studentPtr = new Student("John Doe", 20);

    // Access member functions using the pointer
    cout << "Student Details:" << endl;
    studentPtr->display();

    // Deallocate memory
    delete studentPtr;

    return 0;
}
