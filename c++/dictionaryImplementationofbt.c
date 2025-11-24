#include <iostream> [cite: 388]
#include <string>
using namespace std; [cite: 389]

class Node { [cite: 390]
public: [cite: 391]
    string word, meaning; [cite: 392]
    Node *left, *right; [cite: 393]
    Node(string w, string m) : word(w), meaning(m), left (NULL), right (NULL) [cite: 394]
    {} [cite: 395]
};

// Insert word in BST [cite: 397]
Node* insertNode (Node* root, string w, string m) { [cite: 398]
    if (!root) return new Node(w, m); [cite: 399]
    if (w < root->word) root->left = insertNode (root->left, w, m); [cite: 400]
    else if (w > root->word) root->right = insertNode(root->right, w, m); [cite: 401]
    return root; [cite: 401]
} [cite: 402]

// Find minimum (for delete) [cite: 403]
Node* findMin (Node* root) { [cite: 404]
    while (root->left) root = root->left; [cite: 405]
    return root; [cite: 406]
} [cite: 407]

// Delete a word [cite: 408]
Node* deleteNode (Node* root, string w) { [cite: 409]
    if (!root) return NULL; [cite: 410]

    if (w < root->word) root->left = deleteNode(root->left, w); [cite: 411]
    else if (w > root->word) root->right = deleteNode (root->right, w); [cite: 411]
    else { [cite: 411]
        // Case 1: No child or one child
        if (!root->left) { Node* r = root->right; delete root; return r; } [cite: 412]
        if (!root->right) { Node* l = root->left; delete root; [cite: 412]
        return l; } [cite: 413]

        // Case 3: Two children (replace with inorder successor)
        Node* temp = findMin (root->right); [cite: 413]
        root->word = temp->word; [cite: 414]
        root->meaning = temp->meaning; [cite: 415]
        root->right = deleteNode(root->right, temp->word); [cite: 416]
    }
    return root; [cite: 418]
} [cite: 419]

// Display dictionary (in alphabetical order) [cite: 420]
void inorder (Node* root) { [cite: 421]
    if (!root) return; [cite: 422]
    inorder(root->left); [cite: 423]
    cout << root->word << " : " << root->meaning << endl; [cite: 424]
    inorder(root->right); [cite: 425]
} [cite: 426]

int main() { [cite: 427]
    Node* root = NULL; [cite: 428]
    root = insertNode(root, "apple", "a fruit"); [cite: 429, 430]
    root = insertNode(root, "ball", "a round object"); [cite: 431]
    root = insertNode(root, "cat", "an animal"); [cite: 432]

    cout << "\nDictionary Before Deletion:\n";
    inorder (root);

    root = deleteNode (root, "ball");

    cout << "\nDictionary After Deletion:\n";
    inorder(root);

    return 0;
} [cite: 434]