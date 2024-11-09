#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void writeNumbersToFile(const string& filename, const vector<int>& numbers) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int number : numbers) {
            file << number << " ";
        }
        file.close();
        cout << "Дані були успішно записані у файл " << filename << endl;
    } else {
        cerr << "Помилка відкриття файлу " << filename << " для запису" << endl;
    }
}

vector<int> readNumbersFromFile(const string& filename) {
    vector<int> numbers;
    ifstream file(filename);
    int number;
    if (file.is_open()) {
        while (file >> number) {
            numbers.push_back(number);
        }
        file.close();
    } else {
        cerr << "Помилка відкриття файлу " << filename << " для читання" << endl;
    }
    return numbers;
}

int findMaxIndex(const vector<int>& numbers) {
    return distance(numbers.begin(), max_element(numbers.begin(), numbers.end()));
}

int findMinIndex(const vector<int>& numbers) {
    return distance(numbers.begin(), min_element(numbers.begin(), numbers.end()));
}

void swapMaxMin(vector<int>& numbers) {
    int maxIndex = findMaxIndex(numbers);
    int minIndex = findMinIndex(numbers);
    swap(numbers[maxIndex], numbers[minIndex]);
}

int main() {
    vector<int> data = {7, -5, 3, 4, 6, 1, 8, 100};
    writeNumbersToFile("f.txt", data);

    vector<int> numbers = readNumbersFromFile("f.txt");

    swapMaxMin(numbers);

    writeNumbersToFile("g.txt", numbers);

    return 0;
}
