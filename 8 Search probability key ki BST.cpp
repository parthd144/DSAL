#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

public:
    BST() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void buildOptimalBST(int keys[], double probabilities[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (probabilities[j] > probabilities[j + 1]) {
                    swap(probabilities[j], probabilities[j + 1]);
                    swap(keys[j], keys[j + 1]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            insert(keys[i]);
        }
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    int* keys = new int[n];
    double* probabilities = new double[n];
    cout << "Enter the keys in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    cout << "Enter the access probabilities for each key: ";
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }
    BST bst;
    bst.buildOptimalBST(keys, probabilities, n);
    cout << "Inorder traversal of the optimal BST: ";
    bst.inorder(bst.getRoot());
    cout << endl;
    delete[] keys;
    delete[] probabilities;
    return 0;
}

