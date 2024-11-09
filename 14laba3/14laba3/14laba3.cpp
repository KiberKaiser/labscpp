#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, n;
    cout << "Введіть кількість рядків (m <= 4): ";
    cin >> m;
    cout << "Введіть кількість стовпчиків (n <= 3) : ";
    cin >> n;

    if (m > 4 || n > 3) {
        cout << "Розміри матриць не відповідають умовам." << endl;
        return 1;
    }

    double** A = new double* [m];
    for (int i = 0; i < m; ++i) {
        A[i] = new double[n];
    }

   
    cout << "Введіть елементи матриці: " << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    
    double* B = new double[m * n];  
    double* C = new double[m * n];  
    int countPositive = 0;
    int countNegative = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] > 0) {
                B[countPositive++] = A[i][j];
            }
            else if (A[i][j] < 0) {
                C[countNegative++] = A[i][j];
            }
        }
    }
   
    cout << "Додатні елементи (B): ";
    for (int i = 0; i < countPositive; ++i) {
       cout << B[i] << " ";
    }
    cout << endl;

    cout << "Від'ємні елементи (С): ";
    for (int i = 0; i < countNegative; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    cout << "Кількість додатних елементів: " << countPositive << endl;
    cout << "Кількість від'ємних елементів: " << countNegative << endl;

    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}

