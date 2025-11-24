#include <iostream> [cite: 83]
using namespace std; [cite: 84]

class Node { [cite: 85]
public: [cite: 86]
    int data; [cite: 87]
    Node* left; [cite: 88]
    Node* right; [cite: 89]
    Node(int value) { [cite: 90]
        data = value; [cite: 91]
        left = right = nullptr; [cite: 92]
    } [cite: 93]
}; [cite: 94]

Node* insertNode (Node* root, int value) { [cite: 95]
    if (root == nullptr) { [cite: 96]
        return new Node(value); [cite: 97]
    } [cite: 99]
    if (value < root->data) { [cite: 100]
        root->left = insertNode(root->left, value); [cite: 101]
    } else if (value > root->data) { [cite: 102]
        root->right = insertNode(root->right, value); [cite: 103]
    }
    return root; [cite: 105]
}

void inorder (Node* root) { [cite: 106]
    if (root == nullptr) return; [cite: 108]
    inorder(root->left); [cite: 109]
    cout << root->data << " "; [cite: 110]
    inorder(root->right); [cite: 111]
} [cite: 107]

void preorder (Node* root) { [cite: 112]
    if (root == nullptr) return; [cite: 113]
    cout << root->data << " "; [cite: 114]
    preorder (root->left); [cite: 115]
    preorder (root->right); [cite: 116]
}

void postorder (Node* root) { [cite: 117]
    if (root == nullptr) return; [cite: 118]
    postorder(root->left); [cite: 119]
    postorder(root->right); [cite: 120]
    cout << root->data << " "; [cite: 121]
}

int main() { [cite: 122]
    Node* root = nullptr; [cite: 123]
    int n, value; [cite: 124]
    cout << "Enter number of nodes to insert: "; [cite: 125]
    cin >> n; [cite: 126]
    cout << "Enter " << n << " values: \n"; [cite: 128]
    for (int i = 0; i < n; i++) { [cite: 129]
        cin >> value; [cite: 131]
        root = insertNode(root, value); [cite: 130, 132]
    } [cite: 133]

    cout << "\nInorder Traversal : "; [cite: 134, 135]
    inorder (root); [cite: 136]

    cout << "\nPreorder Traversal : "; [cite: 137, 138]
    preorder(root); [cite: 139]

    cout << "\nPostorder Traversal: "; [cite: 140]
    postorder(root); [cite: 141]

    cout << endl; [cite: 142]
    return 0; [cite: 143]
}