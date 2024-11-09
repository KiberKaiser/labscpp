#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n; 
	cout << "Введіть розмір масиву, де n <= 13: ";
	cin >> n;
	if (n <= 0 || n > 13) {
		cout << "Неправильний розмір масиву";
		return 1;
	}
	double* A = new double[n];

	cout << "Введіть елементи масиву: ";
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
		cout << "Мінімальний позитивний елемент масиву: " << minPositive; 
	}
	else {
		cout << "Немає позитивних елементів в масиві";
	}
	delete[] A;
	return 0;
}