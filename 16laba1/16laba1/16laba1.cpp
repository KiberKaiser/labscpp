#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string fruits = "���������, ������, �����, �����, ��������, ������";
	ofstream outputFileF("f.txt");
	outputFileF << fruits;
	outputFileF.close();

	
	
	ofstream outputFileG("g.txt");
	vector<string> words;
	stringstream ss(fruits);
	string word;
	while (getline(ss, word, ',')) {
		words.push_back(word);
	}

	reverse(fruits.begin(), fruits.end());
	for (int i = words.size() - 1; i >= 0; --i) {
		outputFileG << words[i];
		if (i != 0) {
			outputFileG << ",";
		}
	}
	outputFileG.close();
	cout << "����� ���� ������ ������� � ���� g.txt � ���������� �������.";
	return 0;
}
