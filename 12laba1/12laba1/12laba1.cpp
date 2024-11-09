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
        {"��������", 3, 4, 5},
        {"��������", 4, 2, 4},
        {"���������", 5, 3, 4},
        {"����", 5, 5, 5},
        {"�����", 3, 4, 4}
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

    
    cout << "������� ��� � ���� ����������: " << avgHigherMath << endl;
    cout << "������� ��� � ������: " << avgPhysics << endl;
    cout << "������� ��� � ��������� ������: " << avgNumericalMethods << endl;

    return 0;
}

