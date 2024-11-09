#include <iostream>

using namespace std;
double a[6] = { 1.5, 1.3, 2.0, 3.6, 4.1, -1.6 };
double b[6] = { 2.1, 1.5, -1.0, 2.3, 4.3, 5.6 };
double calculateQ(int m, int n) {
    double sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = m; i <= n; i++) {
        sum1 += a[i];
        sum2 += pow(a[i], 2) - b[i];
        sum3 += b[i] * a[i];
    }
    double Q = sum1 + sum2 + sum3;
    return Q;
}

int main() {
    cout << "result: " << calculateQ(1, 6) << endl;
    return 0;
}



