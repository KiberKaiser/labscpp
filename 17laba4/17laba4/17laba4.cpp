#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
#include <queue>
#include <Windows.h>
using namespace std;


struct Node {
    double value;
    Node* left;
    Node* right;
    Node(double val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, double value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << ' ';
    cout << root->value << "\n";
    printTree(root->left, space);
}

    double evaluatePostfix(const string & expression) {
        stack<double> operands; 
        stringstream ss(expression);
        string token;

        while (ss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                operands.push(stod(token));
            }
            else {
                double operand2 = operands.top(); operands.pop();
                double operand1 = operands.top(); operands.pop();

                switch (token[0]) {
                case '+': operands.push(operand1 + operand2); break;
                case '-': operands.push(operand1 - operand2); break;
                case '*': operands.push(operand1 * operand2); break;
                case '/': operands.push(operand1 / operand2); break;
                case '^': operands.push(pow(operand1, operand2)); break;
                default: throw runtime_error("Unsupported operation");
                }
            }
        }

        return operands.top();
    }

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string postfix = "3 4 2 * 1 5 - 2 3  ^";
    cout << "Постфіксний вираз: " << postfix << endl;
 
        double result = evaluatePostfix(postfix);
        cout << "Результат: " << result << endl;

        Node* root = nullptr;
        stringstream ss(postfix);
        string token;
        while (ss >> token) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                root = insertNode(root, stod(token));
            }
        }

        cout << "Бінарне дерево:\n";
        printTree(root);
    return 0;
}