#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(string key, string value) {
        keyword = key;
        meaning = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == NULL)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insertNode(Node* node, string key, string value) {
        if (node == NULL)
            return new Node(key, value);

        if (key < node->keyword)
            node->left = insertNode(node->left, key, value);
        else if (key > node->keyword)
            node->right = insertNode(node->right, key, value);
        else
            node->meaning = value;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && key < node->left->keyword)
            return rightRotate(node);

        if (balanceFactor < -1 && key > node->right->keyword)
            return leftRotate(node);

        if (balanceFactor > 1 && key > node->left->keyword) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balanceFactor < -1 && key < node->right->keyword) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* findMinNode(Node* node) {
        if (node == NULL || node->left == NULL)
            return node;
        return findMinNode(node->left);
    }

    Node* deleteNode(Node* node, string key) {
        if (node == NULL)
            return node;

        if (key < node->keyword)
            node->left = deleteNode(node->left, key);
        else if (key > node->keyword)
            node->right = deleteNode(node->right, key);
        else {
            if (node->left == NULL || node->right == NULL) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMinNode(node->right);
                node->keyword = temp->keyword;
                node->meaning = temp->meaning;
                node->right = deleteNode(node->right, temp->keyword);
            }
        }

        if (node == NULL)
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rightRotate(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return leftRotate(node);

        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node* node) {
        if (node == NULL)
            return;

        inorderTraversal(node->left);
        cout << node->keyword << ": " << node->meaning << endl;
        inorderTraversal(node->right);
    }

    void reverseInorderTraversal(Node* node) {
        if (node == NULL)
            return;

        reverseInorderTraversal(node->right);
        cout << node->keyword << ": " << node->meaning << endl;
        reverseInorderTraversal(node->left);
    }

    int getMaxComparisons(Node* node, string key) {
        if (node == NULL)
            return 0;

        if (key == node->keyword)
            return 1;

        if (key < node->keyword)
            return 1 + getMaxComparisons(node->left, key);

        return 1 + getMaxComparisons(node->right, key);
    }

public:
    AVLTree() {
        root = NULL;
    }

    void insert(string key, string value) {
        root = insertNode(root, key, value);
    }

    void remove(string key) {
        root = deleteNode(root, key);
    }

    void displayAscending() {
        inorderTraversal(root);
    }

    void displayDescending() {
        reverseInorderTraversal(root);
    }

    int getMaxComparisons(string key) {
        return getMaxComparisons(root, key);
    }
};

int main() {
    AVLTree dictionary;
    int choice;
    string keyword, meaning;

    while (true) {
        cout << "-----------------------------" << endl;
        cout << "Dictionary Menu:" << endl;
        cout << "1. Add a new keyword" << endl;
        cout << "2. Delete a keyword" << endl;
        cout << "3. Update the meaning of a keyword" << endl;
        cout << "4. Display the dictionary in ascending order" << endl;
        cout << "5. Display the dictionary in descending order" << endl;
        cout << "6. Find the maximum comparisons required for a keyword" << endl;
        cout << "7. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the keyword: ";
                cin >> keyword;
                cout << "Enter the meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insert(keyword, meaning);
                cout << "Keyword added successfully!" << endl;
                break;
            case 2:
                cout << "Enter the keyword to delete: ";
                cin >> keyword;
                dictionary.remove(keyword);
                cout << "Keyword deleted successfully!" << endl;
                break;
            case 3:
                cout << "Enter the keyword to update: ";
                cin >> keyword;
                cout << "Enter the new meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insert(keyword, meaning);
                cout << "Keyword updated successfully!" << endl;
                break;
            case 4:
                cout << "Dictionary in ascending order:" << endl;
                dictionary.displayAscending();
                break;
            case 5:
                cout << "Dictionary in descending order:" << endl;
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Enter the keyword to find maximum comparisons: ";
                cin >> keyword;
                cout << "Maximum comparisons required: " << dictionary.getMaxComparisons(keyword) << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

