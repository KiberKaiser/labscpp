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
    cout << "������ �������� ������: " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "����� " << i + 1 << ":";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "���� �������:" << endl;
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

    cout << "\n���� ������� ��������: " << sumPositive << endl;
    cout << "ʳ������ ������� ��������: " << countPositive << endl;
    cout << "���� ��'����� ��������: " << sumNegative << endl;
    cout << "ʳ������ ��'����� ��������: " << countNegative << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

