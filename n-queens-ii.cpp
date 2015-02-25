#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int totalNQueens(int n)
    {
        int res = 0;
        dfs(res, 0, 0, 0, n, 0);
        return res;
    }

private:
    void dfs(int &res, uint32_t l, uint32_t r, uint32_t v, int n, int dep)
    {
        if (dep == n) {
            res++;
            return;
        }

        uint32_t map = l | r | v;

        for (int i = 0; i < n; ++i) {
            int mask = 1 << (n - 1 - i);
            if ((map & mask) == 0) {
                dfs(res, (l|mask) << 1 , (r|mask) >> 1, v|mask, n, dep + 1);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.totalNQueens(14) << endl;
    return 0;
}
