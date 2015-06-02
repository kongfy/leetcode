#include <vector>
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

    TrieNode* root;
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words)
    {
        Trie trie;
        for (string &word : words) {
            trie.insert(word);
        }

        vector<string> ans;

        int n = board.size();
        if (n == 0) {
            return ans;
        }

        int m = board[0].size();
        if (m == 0) {
            return ans;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                vector<vector<bool> > check(n, vector<bool> (m, false));
                dfs(board, trie.root, i, j, check, n, m, ans, "");
            }
        }
    }

private:
    void dfs(vector<vector<char> > &board, TrieNode *node, int x, int y, vector<vector<bool> > &check, int n, int m, vector<string> &ans, string pre)
    {
        TrieNode *next = node->child[board[x][y] - 'a'];
        if (!next) {
            return;
        }

        string now = pre + board[x][y];
        if (next->mark) {
            ans.push_back(now);
            next->mark = false;
        }

        check[x][y] = true;

        if (x > 0 && !check[x-1][y]) dfs(board, next, x - 1, y, check, n, m, ans, now);
        if (x < n - 1 && !check[x+1][y]) dfs(board, next, x + 1, y, check, n, m, ans, now);
        if (y > 0 && !check[x][y-1]) dfs(board, next, x, y - 1, check, n, m, ans, now);
        if (y < m - 1 && !check[x][y+1]) dfs(board, next, x, y + 1, check, n, m, ans, now);

        check[x][y] = false;
    }

};
