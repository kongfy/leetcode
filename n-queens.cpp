#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > res;
        vector<string> temp(n, string(n, '.'));

        dfs(res, temp, 0, 0, 0, n, 0);
        return res;
    }

private:
    void dfs(vector<vector<string> > &res, vector<string> &temp, uint32_t l, uint32_t r, uint32_t v, int n, int dep)
    {
        if (dep == n) {
            res.push_back(temp);
            return;
        }

        uint32_t map = l | r | v;

        for (int i = 0; i < n; ++i) {
            int mask = 1 << (n - 1 - i);
            if ((map & mask) == 0) {
                temp[dep][i] = 'Q';

                dfs(res, temp, (l|mask) << 1 , (r|mask) >> 1, v|mask, n, dep + 1);

                temp[dep][i] = '.';
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    vector<vector<string> > res = solver.solveNQueens(8);

    for (vector<string> &queens : res) {
        for (string &str : queens) {
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}
