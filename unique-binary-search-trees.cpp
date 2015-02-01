#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0) {
            return 0;
        }

        vector<vector<int> > f(n, vector<int> (n));

        // init
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }

        // dp
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    if (k == i) {
                        f[i][j] += f[i + 1][j];
                    } else if (k == j) {
                        f[i][j] += f[i][j - 1];
                    } else {
                        f[i][j] += f[i][k - 1] * f[k + 1][j];
                    }
                }
            }
        }

        return f[0][n - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.numTrees(3) << endl;

    return 0;
}
