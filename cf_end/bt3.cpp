#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

void countNumbers(Node* root, int& primeCount, int& oddCount, int& evenCount, int& naturalCount) {
    if (root == nullptr) return;
    int data = root->data;
    if (isPrime(data)) primeCount++;
    if (data % 2 == 0) evenCount++;
    else oddCount++;
    if (data > 0) naturalCount++;
    countNumbers(root->left, primeCount, oddCount, evenCount, naturalCount);
    countNumbers(root->right, primeCount, oddCount, evenCount, naturalCount);
}

int main() {
    Node* root = nullptr;
    int elements[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6};

    cout << "Elements: ";
    for(int i = 0; i<10l; i++) cout << elements[i] << " ";
    cout << endl;
   

    for (int i = 0; i < 10; i++) {
        root = insertNode(root, elements[i]);
    }

    int primeCount = 0, oddCount = 0, evenCount = 0, naturalCount = 0;
    countNumbers(root, primeCount, oddCount, evenCount, naturalCount);

    cout << "Prime numbers: " << primeCount << endl;
    cout << "Odd numbers: " << oddCount << endl;
    cout << "Even numbers: " << evenCount << endl;
    cout << "Natural numbers: " << naturalCount << endl;

    return 0;
}
