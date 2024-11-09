#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

bool checkLetters(const std::string& text) {
    int countA = 0, countB = 0;

    for (char c : text) {
        if (c == '�' || c == '�') {
            ++countA;
        }
        else if (c == '�' || c == '�') {
            ++countB;
        }
    }

    return countA > countB;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text = "�  A  � � � ";

    if (checkLetters(text)) {
        cout << "TRUE";
    }
    else {
        cout << "FALSE";
    }

    return 0;
}