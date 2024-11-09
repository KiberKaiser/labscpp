#include <iostream>
using namespace std;
double a[10] = { 1.1, 2.4, 3.3, 5.4, -2.2, 2.2, -1, 0.5, -2, 0.4 };
double b[9] = { 1.2, -3, 4, -5, 0.1, 0.2, 6.1, 2, -3 };
double x = 0.05;
double y = 16.55;
double productFunction1(int m, int n) {
    double pr = 1;
    for (int i = m; i <= n; i++) {
        pr *= sin(a[i] - b[i]);
    }
    return pr;
}
double productFunction2(int m, int n) {
    double pr = 1;
    for (int i = m; i <= n; i++) {
        pr *= sin(b[i] - a[i]);
    }
    return pr;
}
double logFunction(double a, double b) {

    double ln = log(abs(1 + a * tan(b)));
    return ln;
}
int main()
{ 
    double S = (productFunction1(1, 10)/logFunction(x, y) ) + (logFunction(1, x)/productFunction2(1, 7) + (logFunction(2, 0.3)/productFunction1(3,9)));
    cout << "result:" << S;
    return 0;
}

