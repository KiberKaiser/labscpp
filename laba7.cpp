#include <iostream>
using namespace std;
 

int main()
{

	cout << "7.1" << endl;
	double y[] = {-7.9, 1.0, 1.1, -2.2, 5.0, -1.1, 2.0};
    int sizey = sizeof(y) / sizeof(y[0]);

    cout << "poryadkovi nomeru:";
    for (int i = 0; i < sizey; i++) {
        if (y[i] < 0) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

	cout << "7.2" << endl;
	double A[] = {1.1, -3.3, -6.9, 1.3, 5.3, 6.3, -3.2, 8.1};
    int countnegative, countpositive;
    double sumnegative, sumpositive;
    double averagenegative, averagepositive;
	int sizeA = sizeof(A) / sizeof(A[0]);
    
    for (int i = 0; i < sizeA; i++) {
        if (A[i] < 0) {
            sumnegative += A[i];
            countnegative++;
        } else {
            sumpositive += A[i];
            countpositive++;
        }
    }
    
    if (countnegative > 0) {
        averagenegative = sumnegative / countnegative;
    }
    if (countpositive > 0) {
        averagepositive = sumpositive / countpositive;
    }

    cout << averagenegative << endl;
    cout << averagepositive << endl;

    double difference = averagenegative - averagepositive;
    cout << difference << endl;


}