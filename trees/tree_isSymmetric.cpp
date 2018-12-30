#include <iostream>
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

bool isTreeSymmetric_helper(Node * root1, Node * root2)
{
    if (root1 == nullptr && root2 == nullptr) {return true;}
    else if (root1 == nullptr || root2 == nullptr) {return false;}

    if (root1->key != root2->key) {return false;}
    return isTreeSymmetric_helper(root1->left, root2->right) && isTreeSymmetric_helper(root1->right, root2->left);
}

bool isTreeSymmetric(Node * root)
{
    return isTreeSymmetric_helper(root, root);
}

int main()
{
    //create a tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    cout << "Q: Is tree symmetric?" << endl;
    isTreeSymmetric(root) ? cout << "A: yes" << endl : cout <<"A: no" << endl;

    return 0;
}
