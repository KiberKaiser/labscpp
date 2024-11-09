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
    Student* next;
};
Student* first = nullptr;
Student* last = nullptr;
Student* c;

void printTable() {
    cout << left << setw(5) << "�" << setw(20) << "�������" << setw(25) << "������������ �����"
        << setw(15) << "�������������" << setw(25) << "��������� �������" << setw(20) << "�������/��������" << endl;
    c = first;
    while (c != nullptr) {
        cout << left << setw(5) << c->id << setw(20) << c->surname
            << setw(25) << c->mathAnalysisGrade << setw(15) << c->programmingGrade
            << setw(25) << c->OSGrade << setw(20) << c->algebraGeometryGrade << endl;
        c = c->next;
    }
}
void printProgrammingHighGrades() {
    int goodExcellentCount = 0;
    c = first;
    cout << left << setw(5) << "�" << setw(20) << "�������" << "�������������" << endl;
    while(c != nullptr){
        if (c->programmingGrade == 4 || c->programmingGrade == 5) {
            cout << left << setw(5) << c->id << setw(20) << c->surname
                << c->programmingGrade << endl;
        }
        if (c->programmingGrade == 4 || c->programmingGrade == 5) {
            goodExcellentCount++;
        }
        c = c->next;
    }
    cout << "ʳ������ �������� � ������� 5: " << goodExcellentCount << endl;
}

void InInfo(int n) {
    for (int i = 0; i < n; i++) {
        c = new Student;
     
        cout << "������ ���������� ��� �������� #" << (i + 1) << endl;
        c->id = i + 1;
        cout << "�����:" << endl;
        cin >> c->surname;
        cout << "������ � ������������� ������: ";
        cin >> c->mathAnalysisGrade;
        cout << "������ � �������������: ";
        cin >> c->programmingGrade;
        cout << "������ � ����������� ������: ";
        cin >> c->OSGrade;
        cout << "������ � �������/�������: ";
        cin >> c->algebraGeometryGrade;
        c->next = nullptr;



        if (first == nullptr) {
            first = c;
            last = c;
        }
        else {
            last->next = c;
            last = c;
        }
    
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "������ ������� ��������: ";
    cin >> n;

    if (n > 0)
    {
        InInfo(n);
        printTable();
        printProgrammingHighGrades();
    }
    else {
        cout << "ʳ������ �������� �� ���� ����� 0";
    }

    return 0;
}
