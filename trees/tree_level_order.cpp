#include <queue>
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

vector<vector<int>> level_order(Node * root)
{
    vector<vector<int>> result;
    if (root == nullptr) {return result;}

    //BFS
    queue<Node*> q;
    q.push(root);
    q.push(nullptr); //flag indicating the end of a level
    result.push_back(vector<int>()); //vector constructor for current level

    while (!q.empty())
    {
        Node *item = q.front(); q.pop();

        if (item == nullptr) //a level is finished
        {
            if (q.empty()) {break;} //no more levels
            q.push(nullptr); //for the next level
            result.push_back(vector<int>()); //for the next level
        }
        else
        {
            result.back().push_back(item->key);
            if (item->left) {q.push(item->left);}
            if (item->right) {q.push(item->right);}
        }
    }
    return result;
}

int main()
{
    //create a binary tree
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "level order traversal: " << endl;
    vector<vector<int>> result;
    result = level_order(root);

    //print out the result
    for (int i = 0; i < (int) result.size(); ++i)
    {
         for (int j = 0; j < (int) result[i].size(); ++j)
         {
             cout << result[i][j] << " ";         
         }
         cout << endl;
    }

    return 0;
}
