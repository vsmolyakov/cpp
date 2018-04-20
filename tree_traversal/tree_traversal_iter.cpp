#include <iostream>
#include <stack>
#include <vector>
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

void insert(Node* &root, string level, int key)
{
    if (level.length() == 0)
    {
        root = newNode(key);
        return;
    }

    int i = 0;
    Node *ptr = root;
    while (i < level.length()-1)
    {
        if (level[i++] == 'L')
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (level[i] == 'L')
        ptr->left = newNode(key);
    else
        ptr->right = newNode(key);

}

void inorder_iterative(Node *root)
{
    stack<Node*> stack;

    Node *curr = root;

    while (!stack.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

}

int main()
{
    vector<pair<string,int>> keys = 
    {
       {"", 1}, {"L", 2}, {"R", 3}, {"LL", 4}, {"RL", 5},
       {"RR", 6}, {"RLL", 7}, {"RLR", 8}
    };

    Node *root = nullptr;

    for (auto pair: keys)
    {
        insert(root, pair.first, pair.second);
    }

    inorder_iterative(root);
    cout << endl;

    return 0;
}





