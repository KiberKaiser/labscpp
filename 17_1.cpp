#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string lastName;
    vector<int> grades;
};

void printTable(const vector<Student>& students) {
    cout << "No\tПрізвище\tОцінки" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << "\t" << students[i].lastName << "\t\t";
        for (int grade : students[i].grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

void printStupidStudents(const vector<Student>& students) {
    cout << "\nСтуденти з незадовільними оцінками:" << endl;
    for (const auto& student : students) {
        bool unsatisfactory = false;
        for (int grade : student.grades) {
            if (grade < 4) {
                unsatisfactory = true;
                break;
            }
        }
        if (unsatisfactory) {
            cout << student.lastName << endl;
        }
    }
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Введіть прізвище нового студента: ";
    cin.ignore();
    getline(cin, newStudent.lastName);

    cout << "Введіть оцінки студента (введіть -1, щоб закінчити): ";
    int grade;
    while (cin >> grade && grade != -1) {
        newStudent.grades.push_back(grade);
    }

    students.push_back(newStudent);
}

void removeStudent(vector<Student>& students) {
    string lastName;
    cout << "Введіть прізвище студента для видалення: ";
    cin.ignore();
    getline(cin, lastName);

    auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
        return student.lastName == lastName;
    });

    if (it != students.end()) {
        students.erase(it);
        cout << "Студент " << lastName << " успішно видалений." << endl;
    } else {
        cout << "Студент з прізвищем " << lastName << " не знайдений." << endl;
    }
}


int main() {
    vector<Student> students = {
            {"ІванчукС.О.", {3, 4, 4, 4}},
            {"ПанченкоІ.А.", {3, 5, 4}},
            {"ЗаєцьО.М.", {4, 5, 4}},
            {"КравченкоЗ.І.", {4, 3, 3, 5, 4, 4}}
    };

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вивести таблицю студентів" << endl;
        cout << "2. Вивести студентів з незадовільними оцінками" << endl;
        cout << "3. Додати студента" << endl;
        cout << "4. Видалити студента" << endl;
        cout << "5. Вихід" << endl;
        cout << "Виберіть дію: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printTable(students);
                break;
            case 2:
                printStupidStudents(students);
                break;
            case 3:
                addStudent(students);
                break;
            case 4:
                removeStudent(students);
                break;
            case 5:
                cout << "Завершення роботи." << endl;
                break;
            default:
                cout << "Невірний вибір." << endl;
        }
    } while (choice != 5);

    return 0;
}
