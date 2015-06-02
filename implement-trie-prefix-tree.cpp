#include <iostream>
#include <string>

using namespace std;

class TrieNode
{
public:
    // Initialize your data structure here.
    TrieNode()
    {
        mark = false;
        memset(child, 0, sizeof(child));
    }

    bool isLeaf()
    {
        for (int i = 0; i < 26; ++i) {
            if (child[i]) return false;
        }
        return true;
    }

    bool mark;
    TrieNode* child[26];
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;

        int l = s.size();
        if (!l) return;
        for (int i = 0; i < l; ++i) {
            if (!p->child[s[i] - 'a']) {
                p->child[s[i] - 'a'] = new TrieNode();
            }
            p = p->child[s[i] - 'a'];
        }

        p->mark = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = root;

        int l = key.size();
        if (!l) return true;
        for (int i = 0; i < l; ++i) {
            if (!p->child[key[i] - 'a']) {
                return false;
            }
            p = p->child[key[i] - 'a'];
        }

        return p->mark;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *p = root;

        int l = prefix.size();
        if (!l) return true;
        for (int i = 0; i < l; ++i) {
            if (!p->child[prefix[i] - 'a']) {
                return false;
            }
            p = p->child[prefix[i] - 'a'];
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char *argv[])
{
    Trie trie;

    trie.insert("somestring");
    trie.insert("kongfy");

    cout << trie.search("kongfy") << endl;
    cout << trie.search("kongfanyu") << endl;
    cout << trie.search("somestring") << endl;

    cout << trie.startsWith("kong") << endl;
    cout << trie.startsWith("some") << endl;
    cout << trie.startsWith("kongfanyu") << endl;

    return 0;
}
