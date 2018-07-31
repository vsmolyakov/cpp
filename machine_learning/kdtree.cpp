#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define DIM 2
#define KNB 3

struct Node
{
    int point[DIM];      //to store DIM dimensional point
    Node *left, *right;  //binary tree
};

struct Node* newNode(int arr[])
{
    struct Node * temp = new Node;
    
    for (int i = 0; i < DIM; ++i)
    {
        temp->point[i] = arr[i];
    }
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node *root, int point[], unsigned int depth)
{
    if (root == nullptr) {return newNode(point);}

    //cd = current dimension
    unsigned int cd = depth % DIM;
    
    //insert node recursively (similar to BST)
    if (point[cd] < (root->point[cd]))
        root->left = insert(root->left, point, depth+1);
    else
        root->right = insert(root->right, point, depth+1);

    return root;
}

bool samePoint(int point1[], int point2[])
{
    for (int i = 0; i < DIM; ++i)
    {
        if (point1[i] != point2[i])
            return false;
    }
    return true;
}

bool search(Node* root, int point[], unsigned int depth)
{
    //base case
    if (root == nullptr) return false;
    if (samePoint(root->point, point)) return true;

    //cd = current dimension
    unsigned int cd = depth % DIM;
   
    //BST
    if (point[cd] < root->point[cd])
        return search(root->left, point, depth+1);
    else 
        return search(root->right, point, depth+1);

}

int main()
{
    struct Node *root = nullptr;
    int points[][DIM] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};
    int n = sizeof(points) / sizeof(points[0]);

    cout << "building kd tree..." << endl;
    for (int i = 0; i < n; ++i)
    {
        root = insert(root, points[i], 0);
        cout << "(" << points[i][0] << ", " << points[i][1] << ")" << " ";
    }
    cout << endl;

    cout << "querying points..." << endl;
    int point1[] = {10, 19};
    cout << "Point (" << point1[0] << ", " << point1[1] << ") : ";
    (search(root, point1, 0)) ? cout << "found" << endl : cout << "not found" << endl;

    int point2[] = {12, 19};
    cout << "Point (" << point2[0] << ", " << point2[1] << ") : ";
    (search(root, point2, 0)) ? cout << "found" << endl : cout << "not found" << endl;

    return 0;
}









