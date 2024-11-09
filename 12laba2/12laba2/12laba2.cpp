#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string T = "я студент першого курса";
    string N;

    size_t lastSpacePos = T.rfind(' ');

    if (lastSpacePos != string::npos) {
        N = T.substr(lastSpacePos + 1);
        size_t secondLastSpacePos = T.rfind(' ', lastSpacePos - 1);
        if (secondLastSpacePos != string::npos) {
            N = T.substr(secondLastSpacePos + 1);
        }
    }
    else {
        N = T;
    }

    cout << "Результат: " << N << endl;

    return 0;
}



