
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, n;

    cout << "¬вед≥ть розм≥р масиву (m <= 7): ";
    cin >> m;
    cout << "¬вед≥ть розм≥р масиву (n <= 5): ";
    cin >> n;

    if (m > 7 || n > 5) {
        cout << "–озм≥ри матриц≥ не в≥дпов≥дають умовам." << endl;
        return 1;
    }

    double** A = new double* [m];
    for (int i = 0; i < m; ++i) {
        A[i] = new double[n];
    }


    cout << "¬вед≥ть елементи матриц≥:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }


    double sum = 0.0;
    for (int i = 0; i < min(m, n); ++i) {
        if (A[i][i] >= 0) {
            sum += A[i][i];
        }
    }

    cout << "—ума нев≥д'Їмних елемент≥в по головн≥й д≥агонал≥: " << sum << endl;

    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
