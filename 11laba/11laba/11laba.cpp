#include <iostream>
#include <Windows.h>
using namespace std;

int maxdig(int N) {
   
    if (N < 10) {
        return N;
    }
    else {
        int lastDigit = N % 10;
        int restDigitsMax = maxdig(N / 10);
        return max(lastDigit, restDigitsMax);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number = 79562;
    cout << "Найбільша цифра у числі " << number << " : " << maxdig(number) << endl;
    return 0;
}