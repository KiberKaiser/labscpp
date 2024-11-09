#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string lastName;
    vector<int> grades;
};

vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void readExamResults(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу " << filename << " для читання" << endl;
        return;
    }

    string line;
    getline(file, line);

    vector<Student> students;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ';');
        Student student;
        student.lastName = tokens[0];
        for (size_t i = 1; i < tokens.size(); ++i) {
            student.grades.push_back(stoi(tokens[i]));
        }
        students.push_back(student);
    }
    file.close();

    vector<double> subjectAverages(students.front().grades.size(), 0.0);
    for (const auto& student : students) {
        double studentAverage = 0.0;
        for (size_t i = 0; i < student.grades.size(); ++i) {
            subjectAverages[i] += student.grades[i];
            studentAverage += student.grades[i];
        }
        studentAverage /= student.grades.size();
        cout << "Студент " << student.lastName << ": " << studentAverage << endl;
    }

    cout << "Середній бал по кожному предмету:" << endl;
    for (size_t i = 0; i < subjectAverages.size(); ++i) {
        subjectAverages[i] /= students.size();
        cout << "Предмет " << i + 1 << ": " << subjectAverages[i] << endl;
    }
}

int main() {
    readExamResults("exam_results.txt");
    return 0;
}
