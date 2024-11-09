#include <iostream>
using namespace std;

class Array {
private:
    int size;
    int* data;

public:
    Array(int s) : size(s) {
        data = new int[size];
    }

    ~Array() {
        delete[] data;
    }

    void replaceNegativeWithZero() {
        for (int i = 0; i < size; ++i) {
            if (data[i] < 0) {
                data[i] = 0;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << std::endl;
    }

    int getSize() const {
        return size;
    }

    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            cerr << "Помилка: недійсний індекс" << endl;
            return -1;
        }
    }

    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            cerr << "Помилка: недійсний індекс" << endl;
        }
    }
};

int main() {
    Array arr(5);

    arr.setElement(0, 3);
    arr.setElement(1, -2);
    arr.setElement(2, 5);
    arr.setElement(3, -4);
    arr.setElement(4, 1);

    cout << "Початковий масив:" << endl;
    arr.print();

    arr.replaceNegativeWithZero();

    cout << "Масив після заміни від'ємних елементів на нулі:" << endl;
    arr.print();

    return 0;
}
