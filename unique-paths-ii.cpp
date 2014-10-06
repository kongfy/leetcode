#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        if (!obstacleGrid.size()) {
            return 0;
        }

        int n = obstacleGrid.size();
        int m = obstacleGrid.front().size();

        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) {
            return 0;
        }

        vector<int> row(m, 0);
        vector<vector<int> > f(n, row);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    f[i][j] = 1;
                    continue;
                }

                f[i][j] = 0;
                if (!obstacleGrid[i][j]) {
                    if (i > 0) {
                        f[i][j] += f[i - 1][j];
                    }
                    if (j > 0) {
                        f[i][j] += f[i][j - 1];
                    }
                }
            }
        }

        return f[n - 1][m - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    vector<int> row(3, 0);
    vector<vector<int> > grid(3, row);
    grid[1][1] = 1;

    cout << solve.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
