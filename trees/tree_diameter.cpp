#include <iostream>
#include <algorithm>
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

int height(struct Node * node)
{
    //base case
    if (node == nullptr) {return 0;}
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node * root)
{
    if (root == nullptr) {return 0;}

    //case 1: diameter goes through the root
    int res = height(root->left) + height(root->right);

    //case 2: diameter doesn't go through the root
    return max(res, max(diameter(root->left), diameter(root->right)));
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Diameter of the binary tree is: " << diameter(root) << endl;
    return 0;
}
