

#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int sizeA, sizeB;
	cout << "������ ����� ������ �: ";
    cin >> sizeA;
	cout << "������ ����� ������ �: ";
    cin >> sizeB;

    
   

    double* a = new double[sizeA];
    double* b = new double[sizeB];
    const int sizeC = 2 * min(sizeA, sizeB);
    double* c = new double[sizeC];

    cout << "������ �������� ������ A: ";
    for (int i = 0; i < sizeA; ++i) {
        cin >> a[i];
    }

    cout << "������ �������� ������ B: ";
    for (int i = 0; i < sizeB; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < min(sizeA, sizeB); ++i) {
        c[2 * i] = a[i];
        c[2 * i + 1] = b[i];
    }

    cout << "����� C: ";
    for (int i = 0; i < sizeC; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

