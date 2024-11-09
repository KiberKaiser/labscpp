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
        cout << "№\tПрізвище\tМатематичний аналіз\tПрограмування\tОпераційні системи\tАлгебра/Геометрія" << endl;
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
        cout << "№\tПрізвище\tПрограмування" << endl;
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
          {1, "Іванчук С.О.", 4, 3, 3, 5},
          {2, "Панченко І.А.", 5, 4, 4, 4},
          {3, "Заєць О.М.", 3, 2, 4, 4},
          {4, "Кравченко З.І.", 3, 5, 4, 5}
        };

        cout << "Загальна таблиця студентів:" << endl;
        printTable(students);

        cout << "Таблиця студентів з оцінками 4 або 5 за програмування:" << endl;
        printProgrammingHighGrades(students);

        int countHighGrades = countHighProgrammingGrades(students);
        cout << "Кількість студентів з оцінками 4 або 5 за програмування: " << countHighGrades << endl;
    }