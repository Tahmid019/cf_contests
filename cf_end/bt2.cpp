#include <iostream>
#include <cmath>

using namespace std;

// Define the structure of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert function to add nodes to the tree
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

// Function to calculate the height of the tree
int maxDepth(Node *node) {
    if (node == nullptr)
        return 0;

    // compute the depth of left and right subtrees
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);

    return max(lDepth, rDepth) + 1;
}

// Function to calculate the number of nodes in the last level
int ll(Node* root) {
    int height = maxDepth(root);
    cout << height << endl;
    return pow(2, height - 1);
}

int main() {
    Node* root = nullptr;
    int elements[10] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6};

    // Insert elements into the binary tree
    for (int i = 0; i < 10; i++) {
        root = insertNode(root, elements[i]);
    }

    // Calculate the maximum number of nodes in the last level
    int maxNodesLastLevel = ll(root);
    cout << "Maximum number of nodes in the last level: " << maxNodesLastLevel << endl;

    return 0;
}
