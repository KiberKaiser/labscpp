#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
struct Student {
    string name;
    int higherMath;
    int physics;
    int numericalMethods;
};


double calculateAverage(const vector<int>& grades) {
    double sum = 0.0;
    for (int grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Student> students = {
        {"Іваненко", 3, 4, 5},
        {"Петренко", 4, 2, 4},
        {"Сидоренко", 5, 3, 4},
        {"Крук", 5, 5, 5},
        {"Голуб", 3, 4, 4}
    };

  
    vector<int> higherMathGrades;
    vector<int> physicsGrades;
    vector<int> numericalMethodsGrades;

    for (const Student& student : students) {
        higherMathGrades.push_back(student.higherMath);
        physicsGrades.push_back(student.physics);
        numericalMethodsGrades.push_back(student.numericalMethods);
    }

    double avgHigherMath = calculateAverage(higherMathGrades);
    double avgPhysics = calculateAverage(physicsGrades);
    double avgNumericalMethods = calculateAverage(numericalMethodsGrades);

    
    cout << "Середній бал з вищої математики: " << avgHigherMath << endl;
    cout << "Середній бал з фізики: " << avgPhysics << endl;
    cout << "Середній бал з чисельних методів: " << avgNumericalMethods << endl;

    return 0;
}

