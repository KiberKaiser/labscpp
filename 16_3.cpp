#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Worker {
    string name;
    vector<int> products;
};

vector<Worker> readData(const string& filename) {
    vector<Worker> workers;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Worker worker;
            size_t pos = line.find(';');
            worker.name = line.substr(0, pos);
            line = line.substr(pos + 1);
            while ((pos = line.find(';')) != string::npos) {
                worker.products.push_back(stoi(line.substr(0, pos)));
                line = line.substr(pos + 1);
            }
            worker.products.push_back(stoi(line));
            workers.push_back(worker);
        }
        file.close();
    }
    return workers;
}

void writeData(const string& filename, const vector<Worker>& workers) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Worker& worker : workers) {
            file << worker.name << ";";
            for (int count : worker.products) {
                file << count << ";";
            }
            file << endl;
        }
        file.close();
    }
}

void printFullTable(const vector<Worker>& workers) {
    cout << "Прізвище та ініціали;1 день;2 день;3 день;4 день;5 день" << endl;
    for (const Worker& worker : workers) {
        cout << worker.name << ";";
        for (int count : worker.products) {
            cout << count << ";";
        }
        cout << endl;
    }
}

void printWorkersByProduction(const vector<Worker>& workers, int minProducts) {
    cout << "Робітники, які випустили не менше " << minProducts << " виробів:" << endl;
    for (const Worker& worker : workers) {
        for (int count : worker.products) {
            if (count >= minProducts) {
                cout << worker.name << endl;
                break;
            }
        }
    }
}

void addWorker(vector<Worker>& workers) {
    Worker worker;
    cout << "Введіть прізвище та ініціали робітника: ";
    getline(cin, worker.name);
    for (int i = 0; i < 5; ++i) {
        int count;
        cout << "Введіть кількість виробів за " << i + 1 << " день: ";
        cin >> count;
        worker.products.push_back(count);
    }
    workers.push_back(worker);
}


void removeWorker(vector<Worker>& workers) {
    string name;
    cout << "Введіть прізвище та ініціали робітника для видалення: ";
    getline(cin, name);

    for (auto it = workers.begin(); it != workers.end(); ++it) {
        if (it->name == name) {
            workers.erase(it);
            cout << "Робітник " << name << " успішно видалений." << endl;
            return;
        }
    }

    cout << "Робітника з ім'ям " << name << " не знайдено." << endl;
}

int main() {
    string filename = "T.txt";
    vector<Worker> workers = readData(filename);

    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Вивести повну таблицю даних" << endl;
        cout << "2. Вивести інформацію про робітників за кількістю виробів" << endl;
        cout << "3. Додати робітника" << endl;
        cout << "4. Видалити робітника" << endl;
        cout << "5. Вихід" << endl;
        cout << "Виберіть дію: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                printFullTable(workers);
                break;
            case 2: {
                int minProducts;
                cout << "Введіть мінімальну кількість виробів: ";
                cin >> minProducts;
                printWorkersByProduction(workers, minProducts);
                break;
            }
            case 3:
                addWorker(workers);
                writeData(filename, workers);
                break;
            case 4:
                removeWorker(workers);
                writeData(filename, workers);
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