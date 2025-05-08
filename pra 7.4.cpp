#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int marks;
    string grade;

    // Constructor
    Student(string n, int m, string g) : name(n), marks(m), grade(g) {}
};

int main() {
    ifstream file("students.txt");
    vector<Student> students;

    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return 1;
    }

    string name, grade;
    int marks;
    
    while (file >> name >> marks >> grade) {
        students.push_back(Student(name, marks, grade));
    }

    file.close();

    // Display results
    cout << "Student Name   Marks   Grade" << endl;
    for (const auto& student : students) {
        cout << student.name << "   " << student.marks << "   " << student.grade << endl;
    }

    return 0;
}