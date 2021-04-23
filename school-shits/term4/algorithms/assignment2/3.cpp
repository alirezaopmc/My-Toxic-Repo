/*
Write an algorithm that determins whether or not an almost complete
binary tree us heap.
*/

class Node {
public:
    Node *left, *right;
    int value;
};

bool isHeap(Node *node);

int main() {
    // Only algorithm is available
}

bool isHeap(Node *node) {
    if (node == nullptr) return true;

    if (
        node->value < node->left->value ||
        node->value > node->right->value
    ) return false;

    return isHeap(node->left) && isHeap(node->right);
}