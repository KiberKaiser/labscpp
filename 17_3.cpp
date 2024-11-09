#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(const string& newData) : data(newData), next(nullptr) {}
};

void append(Node*& head, const string& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void printWordsWithDigits(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        bool hasDigits = false;
        for (char c : current->data) {
            if (isdigit(c)) {
                hasDigits = true;
                break;
            }
        }
        if (hasDigits) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    string input;
    cout << "Введіть послідовність слів, розділених комами (завершіть крапкою): ";
    while (cin >> input && input != ".") {
        append(head, input);
    }

    cout << "Введені слова: ";
    printList(head);

    cout << "Слова, що містять цифри: ";
    printWordsWithDigits(head);

    deleteList(head);

    return 0;
}
