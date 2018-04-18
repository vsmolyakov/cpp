#include <map>
#include <vector>
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

void get_vertical_order(Node * root, int hd, map<int, vector<int>>& m)
{
    //pre-order tree traversal
    if (root == nullptr)
        return;
    
    m[hd].push_back(root->key); //hash table indexed by horizontal distance (hd)
    get_vertical_order(root->left, hd-1, m);  //decrement hd by 1
    get_vertical_order(root->right, hd+1, m); //increment hd by 1
}

void print_vertical_order(Node * root)
{
    int hd = 0;
    map<int, vector<int>> m;

    get_vertical_order(root, hd, m);

    for (auto item : m)
    {
        for (int i=0; i<item.second.size(); ++i)
        {
            cout << item.second[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //create a tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "vertical order traversal: " << endl;
    print_vertical_order(root);

    return 0;
}
