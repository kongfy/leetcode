#include <string>
#include <iostream>

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


class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word)
    {
        TrieNode *p = root;

        int l = word.size();
        if (!l) return;
        for (int i = 0; i < l; ++i) {
            if (!p->child[word[i] - 'a']) {
                p->child[word[i] - 'a'] = new TrieNode();
            }
            p = p->child[word[i] - 'a'];
        }

        p->mark = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        return search_sub(word, 0, root);
    }

private:
    TrieNode* root;

    bool search_sub(string &word, int dep, TrieNode *node)
    {
        if (dep == word.size()) {
            return node->mark;
        }

        if (word[dep] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->child[i] && search_sub(word, dep + 1, node->child[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->child[word[dep] - 'a']) {
                return search_sub(word, dep + 1, node->child[word[dep] - 'a']);
            } else {
                return false;
            }
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char *argv[])
{
    WordDictionary wordDictionary;

    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    cout << wordDictionary.search("pad") << endl;
    cout << wordDictionary.search("bad") << endl;
    cout << wordDictionary.search(".ad") << endl;
    cout << wordDictionary.search("b..") << endl;

    return 0;
}
