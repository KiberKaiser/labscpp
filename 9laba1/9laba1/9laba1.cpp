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
	cout << "������ ������� ����������(M) �� ������� ������(N): ";
	cin >> M >> N;

    vector<vector<double>> salary(M, vector<double>(N));    /// ��������
    vector<vector<double>> tax(M, vector<double>(N));       ///  �������
    
    for (int i = 0; i < M; i++) {
        cout << "������ �������� ����� ���������� " << i + 1 << " �� " << N << " ������: ";
        for (int j = 0; j < N; j++) {
            cin >> salary[i][j];                    // ���� �������� 
        }
    }

    for (int i = 0; i < M; i++) {
        cout << "�������� ����� ���������� " << i + 1 << " �� ����������� �������: ";
        for (int j = 0; j < N; j++) {
          
            cout << salary[i][j] << " "; 
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        cout << "�������� ����� ���������� " << i + 1 << " ���� ����������� �������: ";
        for (int j = 0; j < N; j++) {
            double netSalary = salary[i][j] * (1 - taxRate);
            cout << netSalary << " ";
        }
        cout << endl;
    }
  

	return 0;
}
