#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class Student {
public:
    int id;
    string surname;
    int mathAnalysisGrade;
    int programmingGrade;
    int OSGrade;
    int algebraGeometryGrade;
    Student(int id, string surname, int mathAnalysisGrade, int programmingGrade, int OSGrade, int algebraGeometryGrade)
    : id(id), surname(surname), mathAnalysisGrade(mathAnalysisGrade), programmingGrade(programmingGrade), OSGrade(OSGrade), algebraGeometryGrade(algebraGeometryGrade) {}
};
class StudentTable {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void printTable() const {
        cout << "�\t�������\t������������ �����\t�������������\t��������� �������\t�������/��������" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << students[i].id << "\t" << students[i].surname << "\t"
                << setw(20) << students[i].mathAnalysisGrade
                << setw(15) << students[i].programmingGrade
                << setw(20) << students[i].OSGrade
                << setw(15) << students[i].algebraGeometryGrade << endl;
        }
    }

    void printProgrammingHighGrades() const {
        cout << "�\t�������\t�������������" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].programmingGrade == 4 || students[i].programmingGrade == 5) {
                cout << students[i].id << "\t" << students[i].surname << "\t"
                    << students[i].programmingGrade << endl;
            }
        }
    }

    int countHighProgrammingGrades() const {
        int count = 0;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].programmingGrade == 4 || students[i].programmingGrade == 5) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StudentTable studentTable;

    studentTable.addStudent(Student(1, "������� �.�.", 4, 3, 3, 5));
    studentTable.addStudent(Student(2, "�������� �.�.", 5, 4, 4, 4));
    studentTable.addStudent(Student(3, "���� �.�.", 3, 2, 4, 4));
    studentTable.addStudent(Student(4, "��������� �.�.", 3, 5, 4, 5));

    cout << "�������� ������� ��������:" << endl;
    studentTable.printTable();

    cout << "������� �������� � �������� 4 ��� 5 �� �������������:" << endl;
    studentTable.printProgrammingHighGrades();

    int countHighGrades = studentTable.countHighProgrammingGrades();
    cout << "ʳ������ �������� � �������� 4 ��� 5 �� �������������: " << countHighGrades << endl;

    return 0;
}