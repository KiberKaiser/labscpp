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
    cout << left << setw(5) << "№" << setw(20) << "Прізвище" << setw(25) << "Математичний аналіз"
        << setw(15) << "Програмування" << setw(25) << "Операційні системи" << setw(20) << "Алгебра/Геометрія" << endl;
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
    cout << left << setw(5) << "№" << setw(20) << "Прізвище" << "Програмування" << endl;
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
    cout << "Кількість студентів з оцінкою 5: " << goodExcellentCount << endl;
}

void InInfo(int n) {
    for (int i = 0; i < n; i++) {
        c = new Student;
     
        cout << "Введіть інформацію про студента #" << (i + 1) << endl;
        c->id = i + 1;
        cout << "Фамілія:" << endl;
        cin >> c->surname;
        cout << "Оцінка з математичного аналізу: ";
        cin >> c->mathAnalysisGrade;
        cout << "Оцінка з програмування: ";
        cin >> c->programmingGrade;
        cout << "Оцінка з операційних систем: ";
        cin >> c->OSGrade;
        cout << "Оцінка з алгебри/геометрії: ";
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
    cout << "Введіть кількість студентів: ";
    cin >> n;

    if (n > 0)
    {
        InInfo(n);
        printTable();
        printProgrammingHighGrades();
    }
    else {
        cout << "Кількість студентів має бути більше 0";
    }

    return 0;
}
