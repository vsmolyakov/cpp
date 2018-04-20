#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

void preorder_traversal(Node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root)
{
    if (root == nullptr)
        return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root)
{
    if (root == nullptr)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << endl << "preorder traversal: ";
    preorder_traversal(root);
    cout << endl << "inorder traversal: ";
    inorder_traversal(root);
    cout << endl << "postorder traversal: ";
    postorder_traversal(root);
    cout << endl;

    return 0;
}





