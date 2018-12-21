#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

struct Node* newNode(int key)
{
    struct Node * node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

bool isValidBST(Node * root, long low, long high)
{
    if (root == nullptr) {return true;}
    return (low < root->key && root->key < high) && isValidBST(root->left, low, root->key) && isValidBST(root->right, root->key, high);
}

int main()
{
    //create a tree
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    cout << "Q: Is valid BST?" << endl;
    isValidBST(root, LONG_MIN, LONG_MAX) ? cout << "A: yes" << endl : cout <<"A: no" << endl;

    return 0;
}
