#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        int m = dungeon.size();
        if (m == 0) {
            return 1;
        }

        int n = dungeon[0].size();
        if (n == 0) {
            return 1;
        }

        vector<vector<int> > f(m, vector<int> (n, INT_MAX));
        f[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i != m - 1) {
                    int cost = max(1, f[i + 1][j] - dungeon[i][j]);
                    f[i][j] = min(f[i][j], cost);
                }

                if (j != n - 1) {
                    int cost = max(1, f[i][j + 1] - dungeon[i][j]);
                    f[i][j] = min(f[i][j], cost);
                }
            }
        }

        return f[0][0];
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int> > dungeon(3, vector<int> (3));
    dungeon[0] = {-2, -3, 3};
    dungeon[1] = {-5, -10, 1};
    dungeon[2] = {10, 30, -5};

    Solution solver;
    cout << solver.calculateMinimumHP(dungeon) << endl;
    return 0;
}
