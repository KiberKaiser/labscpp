#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n; 
	cout << "������ ����� ������, �� n <= 13: ";
	cin >> n;
	if (n <= 0 || n > 13) {
		cout << "������������ ����� ������";
		return 1;
	}
	double* A = new double[n];

	cout << "������ �������� ������: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	double minPositive = 0;
	bool foundPositive = false;
	for (int i = 0; i < n; i++) {
		if (A[i] > 0) {
			if (!foundPositive || A[i] < minPositive) {
				minPositive = A[i];
				foundPositive = true;
			}
		}
	}
	if (foundPositive) {
		cout << "̳�������� ���������� ������� ������: " << minPositive; 
	}
	else {
		cout << "���� ���������� �������� � �����";
	}
	delete[] A;
	return 0;
}