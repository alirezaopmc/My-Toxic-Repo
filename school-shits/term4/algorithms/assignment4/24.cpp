#include <iostream>

using namespace std;

class Node
{
private:
public:
    int value;
    Node *left;
    Node *right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {};

friend class BST;
};


class BST
{
private:
public:
    Node *head;
    BST() : head(nullptr) {};
    void insert(int value);
    string search(int value);
};

void BST::insert(int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
    } else {
        Node *t = head;
        while(true) {
            if (value <= t->value) {
                if (t->left != nullptr) {
                    t = t->left;
                } else {
                    t->left = node;
                    break;
                }
            } else {
                if (t->right != nullptr) {
                    t = t->right;
                } else {
                    t->right = node;
                    break;
                }
            }
        }
    }
}

string BST::search(int value) {
    string result;
    Node *t = head;
    while(true) {
        if (value == t->value) {
            return result;
        } else if (value < t->value) {
            if (t->left != nullptr) {
                result += 'L';
                t = t->left;
            } else {
                result += 'X';
                return result;
            }
        } else {
            if (t->right != nullptr) {
                result += 'R';
                t = t->right;
            } else {
                result += 'X';
                return result;
            }
        }
    }
}

int main() {
    BST bst;

    bst.insert(4);
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);

    /*
      4
     / \
    1   6
     \
      3
    */

    cout << bst.search(3) << endl;
    cout << bst.search(2) << endl;
}