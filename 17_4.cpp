#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* createNode(int value) {
    return new Node(value);
}

void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else {
        if (value < root->data) {
            insert(root->left, value);
        } else {
            insert(root->right, value);
        }
    }
}

void printInternalNodes(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr || root->right != nullptr) {
        cout << root->data << " ";
    }

    printInternalNodes(root->left);
    printInternalNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = { 5, 3, 8, 2, 4, 7, 9 };

    for (int value : values) {
        insert(root, value);
    }

    cout << "Внутрішні вершини дерева: ";
    printInternalNodes(root);
    cout << endl;

    return 0;
}
