#include <cstring>
#include <iostream>
using namespace std;

class TrieNode 
{
public:
    TrieNode *next[26]; //pointer to 26 letters of the alphabet
    bool is_word; //is leaf?

    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
public:
    Trie() {root = new TrieNode();}

    //insert a word into the trie
    void insert(string word)
    {
        TrieNode *p = root;
        for (int i = 0; i < (int) word.size(); ++i)
        {
            if (p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }

    //returns true if a word is in the trie
    bool search(string word)
    {
        TrieNode *p = find(word);
        return p != nullptr && p->is_word;
    }

    //return true if there is any word in the trie
    //that starts with the given prefix
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    TrieNode *root;

    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for (int i = 0; i < (int) key.size() && p != nullptr; ++i)
        {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }
};


int main()
{
    string keys[] = {"everyone", "should", "know", "cpp"};
    int n = sizeof(keys)/sizeof(keys[0]);

    cout << "building a trie..." << endl;
    Trie trie = Trie();
    for (int i = 0; i < n; ++i) {trie.insert(keys[i]);}

    cout << "searching for different keys..." << endl;
    string word1("cpp");
    cout << "Q: Is the word " << word1 << " in the trie ? ";
    trie.search(word1) ? cout << "A: yes" << endl : cout << "A: no" << endl;

    string word2("code");
    cout << "Q: Is the word " << word2 << " in the trie ? ";
    trie.search(word2) ? cout << "A: yes" << endl : cout << "A: no" << endl;

    return 0;
}



