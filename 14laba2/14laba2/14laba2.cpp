
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m, n;

    cout << "������ ����� ������ (m <= 7): ";
    cin >> m;
    cout << "������ ����� ������ (n <= 5): ";
    cin >> n;

    if (m > 7 || n > 5) {
        cout << "������ ������� �� ���������� ������." << endl;
        return 1;
    }

    double** A = new double* [m];
    for (int i = 0; i < m; ++i) {
        A[i] = new double[n];
    }


    cout << "������ �������� �������:" << endl;
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

    cout << "���� ����'����� �������� �� ������� �������: " << sum << endl;

    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
