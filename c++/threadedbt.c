#include <iostream> [cite: 159]
using namespace std; [cite: 160]

class Node [cite: 161]
{ [cite: 162]
public: [cite: 163]
    int data; [cite: 164]
    Node *left, *right; [cite: 165]
    bool rightThread; // true = right pointer is a thread [cite: 166]
    Node(int value) [cite: 167]
    { [cite: 169]
        data = value; [cite: 170]
        left = right = nullptr; [cite: 171]
        rightThread = false; [cite: 172]
    }
}; [cite: 173]

Node *insertNode (Node *root, int value) [cite: 174]
{ [cite: 175]
    if (!root) [cite: 176]
    { [cite: 177]
        return new Node(value); [cite: 178]
    }
    if (value < root->data) [cite: 179]
        root->left = insertNode(root->left, value); [cite: 181]
    else [cite: 180]
        root->right = insertNode(root->right, value); [cite: 182]
    return root; [cite: 183]
}

void createThreaded (Node *root, Node *&prev) [cite: 184]
{ [cite: 185]
    if (!root) [cite: 186]
        return; [cite: 187]

    createThreaded (root->left, prev); [cite: 188]

    // If previous node exists and it has no right child
    if (prev!= nullptr && prev->right == nullptr) [cite: 189, 190]
    { [cite: 191]
        prev->right = root; [cite: 192]
        prev->rightThread = true; // mark as thread [cite: 193, 194]
    }
    prev = root; [cite: 195]

    createThreaded (root->right, prev); [cite: 196]
} [cite: 197]

Node *leftMost (Node *root) [cite: 198]
{ [cite: 199]
    while (root && root->left) [cite: 200]
        root = root->left; [cite: 201, 203]
    return root; [cite: 202]
} [cite: 204]

void inorderThreadedTraversal (Node *root) [cite: 205]
{ [cite: 206]
    Node *current = leftMost(root); [cite: 207]
    while (current != nullptr) [cite: 208]
    { [cite: 209]
        cout << current->data << " "; [cite: 210]

        // If thread exists, just follow the thread
        if (current->rightThread) [cite: 219, 220]
            current = current->right; [cite: 221, 222]
        else // Otherwise, find the leftmost node in the right subtree
            current = leftMost (current->right); [cite: 223, 227]
    } [cite: 211, 224]
}

int main() [cite: 225]
{ [cite: 226]
    Node *root = nullptr; [cite: 228]
    int n, value; [cite: 229]

    cout << "Enter number of nodes: "; [cite: 230]
    cin >> n; [cite: 231]
    cout << "Enter " << n << " values: \n"; [cite: 232]

    for (int i=0; i<n; i++) [cite: 233]
    { [cite: 235]
        cin >> value; [cite: 237]
        root = insertNode(root, value); [cite: 238, 239]
    } [cite: 234, 236]

    // Create threaded binary tree
    Node *prev = nullptr; [cite: 240, 241]
    createThreaded (root, prev); [cite: 242]

    cout << "\nInorder Traversal of Threaded Binary Tree: \n"; [cite: 243]
    inorderThreadedTraversal(root); [cite: 244]

    cout << endl; [cite: 245]
    return 0; [cite: 246]
}