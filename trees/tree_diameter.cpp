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

int diameter(struct Node * tree)
{
    if (tree == nullptr) {return 0;}

    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
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
