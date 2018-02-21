#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node* newNode(char ch, int freq, Node* left, Node* right)
{
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

//comparison object for priority queue
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        //highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

//traverse huffman tree and store huffman codes in a map
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    //leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

//traverse huffman tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
    if (root == nullptr)
        return;

    //leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

void build_huffman_tree(string text)
{
    //histogram of characters
    unordered_map<char, int> freq;
    for (char ch : text){freq[ch]++;}

    //priority queue for creating a huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    //create a leaf node for each character and add it to priority queue
    for (auto pair: freq)
    {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }
   
    while (pq.size() != 1)
    {
        //remove the two nodes of highest priority (lowest frequency) from the queue
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        //create an internal node with these two nodes as children and the frequency
        //equal to the sum of the two nodes' frequencies. Add the new node to priority queue
        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    //root of huffman tree
    Node *root = pq.top();
    
    //store huffman code in a map
    unordered_map<char, string> huffman_code;
    encode(root, "", huffman_code);

    cout << "huffman code: " << endl;
    for (auto pair : huffman_code)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl << "original string: " << endl << text << endl;

    //encoded string
    string str = "";
    for (char ch : text)
    {
        str += huffman_code[ch];
    }
    cout << endl << "encoded string: " << endl << str << endl;

    //decode the encoded string
    int index = -1;
    cout << endl << "decoded string: " << endl;
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
    cout << endl;
}

int main()
{
    string text = "testing huffman coding algorithm";
    build_huffman_tree(text);

    return 0;
}




