#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Student {
private:
    string lastName;

public:
    Student(const string& lastName, const vector<int>& grades) : lastName(lastName), grades(grades) {}

    string getLastName() const {
        return lastName;
    }

    double getAverageGrade() const {
        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    bool hasFailed() const {
        for (int grade : grades) {
            if (grade < 4) {
                return true;
            }
        }
        return false;
    }

    vector<int> grades;
};

vector<Student> createStudentList(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу для читання" << endl;
        return students;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string lastName;
        ss >> lastName;

        vector<int> grades;
        int grade;
        while (ss >> grade) {
            grades.push_back(grade);
        }

        students.push_back(Student(lastName, grades));
    }
    file.close();
    return students;
}

void printFailedStudents(const vector<Student>& students) {
    cout << "Студенти з незадовільними оцінками:" << endl;
    for (const Student& student : students) {
        if (student.hasFailed()) {
            cout << "Прізвище: " << student.getLastName() << endl;
            cout << "Оцінки: ";
            for (int grade : student.grades) {
                cout << grade << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<Student> students = createStudentList("students.txt");
    printFailedStudents(students);
    return 0;
}
