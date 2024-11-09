#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows = 3;
    int cols = 4;

    double** matrix = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }
    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Рядок " << i + 1 << ":";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Вивід матриці:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    double sumPositive = 0, sumNegative = 0;
    int countPositive = 0, countNegative = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > 0) {
                sumPositive += matrix[i][j];
                countPositive++;
            }
            else if (matrix[i][j] < 0) {
                sumNegative += matrix[i][j];
                countNegative++;
            }
        }
    }

    cout << "\nСума додатніх елементів: " << sumPositive << endl;
    cout << "Кількість додатніх елементів: " << countPositive << endl;
    cout << "Сума від'ємних елементів: " << sumNegative << endl;
    cout << "Кількість від'ємних елементів: " << countNegative << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

