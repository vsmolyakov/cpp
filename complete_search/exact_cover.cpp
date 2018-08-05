#include <bits/stdc++.h>
using namespace std;

#define MAX_ROW 100
#define MAX_COL 100

struct Node
{
    struct Node *left;
    struct Node *right;
    struct Node *up;
    struct Node *down;
    struct Node *column;
    int rowID;
    int colID;
    int nodeCount;
};

struct Node *header = new Node();

//matrix that contains nodes of linked mesh
struct Node Matrix[MAX_ROW][MAX_COL];

//binary problem matrix
bool ProbMat[MAX_ROW][MAX_COL];

//vector containing solutions
vector<struct Node*> solutions;

//number of rows and cols
int nRow = 0, nCol = 0;

//circular indices
int getRight(int i){return (i+1) % nCol;}
int getLeft(int i){return (i-1 < 0) ? nCol-1 : i-1;}
int getUp(int i){return (i-1 < 0) ? nRow : i-1;}
int getDown(int i){return (i+1) % (nRow + 1);}

Node* create_toroidal_matrix()
{
    for (int i = 0; i <= nRow; ++i) //one extra row for list header nodes for each col
    {
        for (int j = 0; j < nCol; ++j)
        {
            //create a node if prob matrix has a 1
            if (ProbMat[i][j])
            {
                int a, b;
                
                //skip 0th row
                if (i) Matrix[0][j].nodeCount += 1;
                
                //add pointer to column header
                Matrix[i][j].column = &Matrix[0][j];
                
                //set row and col ID
                Matrix[i][j].rowID = i;
                Matrix[i][j].colID = j;

                //link the node with neighbors
                
                //left pointer
                a = i; b = j;
                do {b = getLeft(b);} while(!ProbMat[a][b] && b != j);
                Matrix[i][j].left = &Matrix[i][b];

                //right pointer
                a = i; b = j;
                do {b = getRight(b);} while(!ProbMat[a][b] && b != j);
                Matrix[i][j].right = &Matrix[i][b];

                //up pointer
                a = i; b = j;
                do {a = getUp(a);} while(!ProbMat[a][b] && a != i);
                Matrix[i][j].up = &Matrix[a][j];

                //down pointer
                a = i; b = j;
                do {a = getDown(a);} while(!ProbMat[a][b] && a != i);
                Matrix[i][j].down = &Matrix[a][j];

            }
        }
    }

    //link header right pointer to column header of first column
    header->right = &Matrix[0][0];

    //link header left pointer to column header of last column
    header->left = &Matrix[0][nCol-1];

    Matrix[0][0].left = header;
    Matrix[0][nCol-1].right = header;

    return header;
}

//cover a given node
void cover(struct Node *targetNode)
{
    struct Node *row, *rightNode;

    //get the pointer to the header of column
    //to which this node belongs 
    struct Node *colNode = targetNode->column;
    
    //unlink column header from its neighbors
    colNode->left->right = colNode->right;
    colNode->right->left = colNode->left;

    //move down the column and remove each row
    //by traversing right
    for (row = colNode->down; row != colNode; row = row->down)
    {
        for (rightNode = row->right; rightNode != row; rightNode = rightNode->right)
        {
            rightNode->up->down = rightNode->down;
            rightNode->down->up = rightNode->up;
            
            //decrement count in column header
            Matrix[0][rightNode->colID].nodeCount -= 1;
        }
    }
}


//uncover a given node (if solution is invalid)
void uncover(struct Node *targetNode)
{
    struct Node *rowNode, *leftNode;

    //get the pointer to the header of column
    //to which this node belongs
    struct Node *colNode = targetNode->column;

    //move down the column and link back each row
    //by traversing left
    for (rowNode = colNode->up; rowNode != colNode; rowNode = rowNode->up)
    {
        for (leftNode = rowNode->left; leftNode != rowNode; leftNode = leftNode->left)
        {
            leftNode->up->down = leftNode;
            leftNode->down->up = leftNode;

            //increment count in column header
            Matrix[0][leftNode->colID].nodeCount += 1;
        }
    }
    
    //link the column header to its neighbors
    colNode->left->right = colNode;
    colNode->right->left = colNode;
}

//traverse column headers right and return the column
//with minimum node count
Node *getMinColumn()
{
    struct Node *h = header;
    struct Node *min_col = h->right;
    h = h->right->right;

    do
    {
        if (h->nodeCount < min_col->nodeCount)
        {
            min_col = h;
        }
        h = h->right;
    } while (h != header);

    return min_col;
}

void printSolution()
{
    cout << "solution: " << endl;
    vector<struct Node*>::iterator i;

    for (i = solutions.begin(); i != solutions.end(); ++i)
    {
        cout << (*i)->rowID <<  " ";
    }
    cout << endl;

}

//search for exact cover
void search(int k)
{
    struct Node *rowNode;
    struct Node *rightNode;
    struct Node *leftNode;
    struct Node *column;

    //if no column left, we found a solution
    if (header->right == header)
    {
        printSolution();
        return;
    }

    //choose column deterministically
    column = getMinColumn();

    //cover chosen column
    cover(column);

    for (rowNode = column->down; rowNode != column; rowNode = rowNode->down)
    {
        solutions.push_back(rowNode);

        for (rightNode = rowNode->right; rightNode != rowNode; rightNode = rightNode->right)
        {
            cover(rightNode);
        }

        //move to level k+1 (recursively)
        search(k+1);

        //if solution is not possible, backtrack (uncover)
        //and remove selected row (set) from solution
        solutions.pop_back();

        column = rowNode->column;
        for (leftNode = rowNode->left; leftNode != rowNode; leftNode = leftNode->left)
        {
            uncover(leftNode);
        }

    }
    
    uncover(column);
}

int main()
{
    //exact cover
    //X = {1,2,3,4,5,6,7}
    //set-1 = {1,4,7}
    //set-2 = {1,4}
    //set-3 = {4,5,7}
    //set-4 = {3,5,6}
    //set-5 = {2,3,6,7}
    //set-6 = {2,7}
    //set-7 = {1,4}

    nRow = 7;
    nCol = 7;

    //init problem matrix
    //row 0 corresponds to headers (init with 1)
    for (int i = 0; i <= nRow; ++i)
    {
        for (int j = 0; j < nCol; ++j)
        {
            if (i == 0) ProbMat[i][j] = true;
            else ProbMat[i][j] = false;
        }
    }

    //fill in the problem matrix
    ProbMat[1][0] = true; ProbMat[1][3] = true; ProbMat[1][6] = true;
    ProbMat[2][0] = true; ProbMat[2][3] = true;
    ProbMat[3][3] = true; ProbMat[3][4] = true; ProbMat[3][6] = true;
    ProbMat[4][2] = true; ProbMat[4][4] = true; ProbMat[4][5] = true;
    ProbMat[5][1] = true; ProbMat[5][2] = true; ProbMat[5][5] = true; ProbMat[5][6] = true;
    ProbMat[6][1] = true; ProbMat[6][6] = true;
    ProbMat[7][0] = true; ProbMat[7][3] = true;

    create_toroidal_matrix();

    search(0);

    return 0;
}







