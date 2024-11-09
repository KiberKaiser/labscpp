#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int M, N;
    double taxRate = 0.25;
	cout << "Введіть кількість працівників(M) та кількість місяців(N): ";
	cin >> M >> N;

    vector<vector<double>> salary(M, vector<double>(N));    /// зарплата
    vector<vector<double>> tax(M, vector<double>(N));       ///  податок
    
    for (int i = 0; i < M; i++) {
        cout << "Введіть заробітну плату працівника " << i + 1 << " за " << N << " місяців: ";
        for (int j = 0; j < N; j++) {
            cin >> salary[i][j];                    // ввод зарпалти 
        }
    }

    for (int i = 0; i < M; i++) {
        cout << "Заробітна плата працівника " << i + 1 << " до вирахування податку: ";
        for (int j = 0; j < N; j++) {
          
            cout << salary[i][j] << " "; 
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        cout << "Заробітна плата працівника " << i + 1 << " після вирахування податку: ";
        for (int j = 0; j < N; j++) {
            double netSalary = salary[i][j] * (1 - taxRate);
            cout << netSalary << " ";
        }
        cout << endl;
    }
  

	return 0;
}
