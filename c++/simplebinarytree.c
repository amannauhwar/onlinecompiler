#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* buildTree() {
    int value;
    cout << "Enter node value (-1 for no node): ";
    cin >> value;
    if (value == -1) {
        return nullptr;
    }
    // Create the current node
    Node* root = new Node(value);
    cout << "Enter left child of "
         << value << ":\n";
    root->left = buildTree();
    cout << "Enter right child of "
         << value << ":\n";
    root->right = buildTree();
    return root;
}

void inorder (Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder (root->right);
}

void preorder (Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder (root->left);
    preorder (root->right);
}

void postorder (Node* root) {
    if (root == nullptr) return;
    postorder (root->left);
    postorder (root->right);
    cout << root->data << " ";
}

int main() {
    cout << "\n--- Build Your Binary Tree ---\n";
    Node* root = buildTree();

    cout << "\nInorder Traversal : ";
    inorder (root);

    cout << "\nPreorder Traversal : ";
    preorder (root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;
    return 0;
}