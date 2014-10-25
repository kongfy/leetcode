#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        int m = grid.size();

        if (!m) {
            return 0;
        }

        int n = grid.front().size();

        unsigned int f[m][n];
        memset(f, 0xff, sizeof(f));

        f[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    f[i][j] = min(f[i][j], f[i-1][j] + grid[i][j]);
                }

                if (j - 1 >= 0) {
                    f[i][j] = min(f[i][j], f[i][j-1] + grid[i][j]);
                }
            }
        }

        return f[m-1][n-1];
    }
};

int main(int argc, char *argv[])
{
    vector<int> row0 {1,2,3,4};
    vector<int> row1 {4,3,2,1};
    vector<vector<int> > grid {row0, row1};

    Solution solve;
    cout << solve.minPathSum(grid) << endl;

    return 0;
}
