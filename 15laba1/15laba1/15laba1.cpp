#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
    struct Student {     
        int id;
        string surname;
        int mathAnalysisGrade;
        int programmingGrade;
        int OSGrade;
        int algebraGeometryGrade;
    };

    void printTable(const vector<Student>& students) {
        cout << "�\t�������\t������������ �����\t�������������\t��������� �������\t�������/��������" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << students[i].id << "\t" << students[i].surname << "\t"
                << setw(20) << students[i].mathAnalysisGrade
                << setw(15) << students[i].programmingGrade
                << setw(20) << students[i].OSGrade
                << setw(15) << students[i].algebraGeometryGrade << endl;
        }
    }
    void printProgrammingHighGrades(const vector<Student>& students) {
        int goodExcellentCount = 0;
        cout << "�\t�������\t�������������" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].programmingGrade == 4 || students[i].programmingGrade == 5) {
                cout << students[i].id << "\t" << students[i].surname << "\t"
                    << students[i].programmingGrade << endl;
            }
            if (students[i].programmingGrade == 5) {
                goodExcellentCount++;
            }
        }
    }

    int countHighProgrammingGrades(const vector<Student>& students) {
        int count = 0;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].programmingGrade == 4 || students[i].programmingGrade == 5) {
                count++;
            }
        }
        return count;
    }

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        vector<Student> students = {
          {1, "������� �.�.", 4, 3, 3, 5},
          {2, "�������� �.�.", 5, 4, 4, 4},
          {3, "���� �.�.", 3, 2, 4, 4},
          {4, "��������� �.�.", 3, 5, 4, 5}
        };

        cout << "�������� ������� ��������:" << endl;
        printTable(students);

        cout << "������� �������� � �������� 4 ��� 5 �� �������������:" << endl;
        printProgrammingHighGrades(students);

        int countHighGrades = countHighProgrammingGrades(students);
        cout << "ʳ������ �������� � �������� 4 ��� 5 �� �������������: " << countHighGrades << endl;
    }