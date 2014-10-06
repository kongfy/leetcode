#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (!m || !n) {
            return 0;
        }

        int f[n][m];
        memset(f, 0, sizeof f);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    f[i][j] = 1;
                    continue;
                }

                f[i][j] = 0;
                if (i > 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j > 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }

        return f[n - 1][m - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    cout << solve.uniquePaths(1, 1) << endl;
    return 0;
}
