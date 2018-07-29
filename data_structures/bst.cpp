#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node* newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

struct node* insert(struct node* node, int key)
{
    //insert at a leaf
    if (node == nullptr) return newNode(key);

    //otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node; //unchanged node pointer
}

struct node* search(struct node* root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

void inorder(struct node* root)
{
    if (root == nullptr) return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    /* Let's create the following BST
                 50
               /    \
             30     70
            /  \   /  \
           20  40 60  80           */

    struct node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "BST in order traversal: " << endl;
    inorder(root);
    cout << endl;

    int key = 80;
    cout << "BST search: " << key << " -> ";
    struct node* item = search(root, key);
    item != nullptr ? cout << "found" << endl : cout << "not found" << endl;
    
    key = 90;
    cout << "BST search: " << key << " -> ";
    item = search(root, key);
    item != nullptr ? cout << "found" << endl : cout << "not found" << endl;

    return 0;
}
