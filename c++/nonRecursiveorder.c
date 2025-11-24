#include <iostream> [cite: 318]
#include <queue> [cite: 319]
using namespace std; [cite: 320]

class Node { [cite: 321]
public: [cite: 322]
    int data; [cite: 323]
    Node *left, *right; [cite: 324]
    Node(int value) { [cite: 325]
        data = value; [cite: 326]
        left = right = nullptr; [cite: 327]
    } [cite: 328]
}; [cite: 329]

Node* buildTree() { [cite: 330]
    int value; [cite: 331]
    cout << "Enter node value (-1 for no node): "; [cite: 332]
    cin >> value; [cite: 333]
    if (value == -1) [cite: 334]
        return nullptr; [cite: 335]

    Node* root = new Node(value); [cite: 336]
    cout << "Enter left child of " << value << ":\n"; [cite: 337, 338]
    root->left = buildTree(); [cite: 339]

    cout << "Enter right child of " << value << ":\n"; [cite: 340, 341]
    root->right = buildTree(); [cite: 343]
    return root; [cite: 344]
} [cite: 342]

void levelOrderTraversal (Node* root) { [cite: 345]
    if (root == nullptr) [cite: 346]
        return; [cite: 347]

    queue<Node*> q; [cite: 348]
    q.push(root); [cite: 349]

    while (!q.empty()) { [cite: 350]
        Node* current = q.front(); [cite: 371]
        q.pop(); [cite: 372]
        cout << current->data << " "; [cite: 373]

        if (current->left) [cite: 374]
            q.push(current->left); [cite: 375]

        if (current->right) [cite: 376]
            q.push(current->right); [cite: 377]
    } [cite: 378, 370]
}

int main() { [cite: 379]
    cout << "\n--- Build Binary Tree ---\n"; [cite: 381]
    Node* root = buildTree(); [cite: 382]
    cout << "\nLevel Order Traversal (Non-Recursive): "; [cite: 383]
    levelOrderTraversal (root); [cite: 384]
    cout << endl; [cite: 385]
    return 0; [cite: 386]
} [cite: 380]