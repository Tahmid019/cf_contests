#include <iostream>
using namespace std;

// Define the structure of the tree node
struct node {
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert function to add nodes to the tree
node* insertnode(node* root, int data) {
    if (root == nullptr) {
        return new node(data);
    }
    if (data < root->data) {
        root->left = insertnode(root->left, data);
    } else {
        root->right = insertnode(root->right, data);
    }
    return root;
}

// Pre-order traversal (Root, Left, Right)
void preOrder(node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal (Left, Root, Right)
void inOrder(node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order traversal (Left, Right, Root)
void postOrder(node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = nullptr;
    int elements[10] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6};

    // Insert elements into the binary tree
    for (int i = 0; i < 10; i++) {
        root = insertnode(root, elements[i]);
        // cout << root->data << endl;
    }

    // Perform traversals
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
