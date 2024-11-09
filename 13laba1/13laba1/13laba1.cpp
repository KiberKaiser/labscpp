#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "¬вед≥ть розм≥р масиву: ";
    cin >> n;
    int* arr = new int[n];

    std::cout << "¬вед≥ть елементи масиву:" << std::endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int negativeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            ++negativeCount;
        }
    }
    cout << "к≥льк≥сть в≥д'Їмних елемент≥в: " << negativeCount << endl;
    delete[] arr;
    return 0;
}

