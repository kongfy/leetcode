#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        int n = board.size();
        if (n == 0) {
            return word.size() == 0;
        }

        int m = board[0].size();
        if (m == 0) {
            return word.size() == 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool> > check(n, vector<bool> (m, false));
                    if (dfs(board, word, i, j, 0, check, n, m)) return true;
                }
            }
        }

        return false;
    }

private:
    bool dfs(vector<vector<char> > &board, string &word, int x, int y, int p, vector<vector<bool> > &check, int n, int m)
    {
        if (word[p] != board[x][y]) {
            return false;
        }

        if (p == word.size() - 1) {
            return true;
        }

        check[x][y] = true;

        if (x > 0 && !check[x-1][y] && dfs(board, word, x - 1, y, p + 1, check, n, m)) return true;
        if (x < n - 1 && !check[x+1][y] && dfs(board, word, x + 1, y, p + 1, check, n, m)) return true;
        if (y > 0 && !check[x][y-1] && dfs(board, word, x, y - 1, p + 1, check, n, m)) return true;
        if (y < m - 1 && !check[x][y+1] && dfs(board, word, x, y + 1, p + 1, check, n, m)) return true;

        check[x][y] = false;

        return false;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
