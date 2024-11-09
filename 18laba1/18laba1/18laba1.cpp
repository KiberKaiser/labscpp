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
        cout << "№\tПрізвище\tМатематичний аналіз\tПрограмування\tОпераційні системи\tАлгебра/Геометрія" << endl;
        for (size_t i = 0; i < students.size(); i++) {
            cout << students[i].id << "\t" << students[i].surname << "\t"
                << setw(20) << students[i].mathAnalysisGrade
                << setw(15) << students[i].programmingGrade
                << setw(20) << students[i].OSGrade
                << setw(15) << students[i].algebraGeometryGrade << endl;
        }
    }

    void printProgrammingHighGrades() const {
        cout << "№\tПрізвище\tПрограмування" << endl;
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

    studentTable.addStudent(Student(1, "Іванчук С.О.", 4, 3, 3, 5));
    studentTable.addStudent(Student(2, "Панченко І.А.", 5, 4, 4, 4));
    studentTable.addStudent(Student(3, "Заєць О.М.", 3, 2, 4, 4));
    studentTable.addStudent(Student(4, "Кравченко З.І.", 3, 5, 4, 5));

    cout << "Загальна таблиця студентів:" << endl;
    studentTable.printTable();

    cout << "Таблиця студентів з оцінками 4 або 5 за програмування:" << endl;
    studentTable.printProgrammingHighGrades();

    int countHighGrades = studentTable.countHighProgrammingGrades();
    cout << "Кількість студентів з оцінками 4 або 5 за програмування: " << countHighGrades << endl;

    return 0;
}