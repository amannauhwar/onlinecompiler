#include <iostream> [cite: 248]
using namespace std; [cite: 249]

class Node { [cite: 250]
public: [cite: 251]
    int data; [cite: 252]
    Node *left, *right; [cite: 253]
    Node(int value) { [cite: 254]
        data = value; [cite: 255]
        left = right = nullptr; [cite: 256]
    } [cite: 257]
}; [cite: 258]

Node* buildTree() { [cite: 259]
    int value; [cite: 260]
    cout << "Enter node value (-1 for no node): "; [cite: 261]
    cin >> value; [cite: 262]
    if (value == -1) [cite: 263]
        return nullptr; [cite: 264]

    Node* root = new Node(value); [cite: 265]
    cout << "Enter left child of " << value << ":\n"; [cite: 266]
    root->left = buildTree(); [cite: 268]

    cout << "Enter right child of " << value << ":\n"; [cite: 269]
    root->right = buildTree(); [cite: 270]
    return root; [cite: 271]
} [cite: 267]

void preorder (Node* root) { [cite: 272]
    if (root == nullptr) return; [cite: 274]
    cout << root->data << " "; [cite: 275]
    preorder (root->left); [cite: 276]
    preorder (root->right); [cite: 277]
} [cite: 273]

void inorder (Node* root) { [cite: 278]
    if (root == nullptr) return; [cite: 280]
    inorder(root->left); [cite: 280]
    cout << root->data << " "; [cite: 281]
    inorder (root->right); [cite: 282]
} [cite: 279]

void postorder (Node* root) { [cite: 283]
    if (root == nullptr) return; [cite: 285]
    postorder (root->left); [cite: 285]
    postorder(root->right); [cite: 286]
    cout << root->data << " "; [cite: 287]
} [cite: 284]

int main() { [cite: 288]
    cout << "\n--- Build Binary Tree ---\n"; [cite: 306]
    Node* root = buildTree(); [cite: 307]

    cout << "\nPreorder Traversal : "; [cite: 308, 309]
    preorder(root); [cite: 310]

    cout << "\nInorder Traversal : "; [cite: 311, 312]
    inorder(root); [cite: 313]

    cout << "\nPostorder Traversal: "; [cite: 314]
    postorder (root); [cite: 315]

    cout << endl; [cite: 315]
    return 0; [cite: 316]
}