#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

bool checkLetters(const std::string& text) {
    int countA = 0, countB = 0;

    for (char c : text) {
        if (c == 'À' || c == 'à') {
            ++countA;
        }
        else if (c == 'Â' || c == 'â') {
            ++countB;
        }
    }

    return countA > countB;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text = "Â  A  À À Â ";

    if (checkLetters(text)) {
        cout << "TRUE";
    }
    else {
        cout << "FALSE";
    }

    return 0;
}