#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size()) {
            return false;
        }

        // use array instead of vector to speed up computation
        bool f[n][n][n];
        memset(f, false, sizeof(bool) * n * n * n);

        // vector<vector<vector<bool> > > f(n, vector<vector<bool> > (n, vector<bool> (n, false)));

        // init
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s1[j] == s2[i]) {
                    f[i][i][j] = true;
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int l = j - i + 1;
                for (int s = n - l; s >= 0; --s) {
                    for (int k = i + 1; k <= j; ++k) {
                        f[i][j][s] = (f[i][k-1][s] && f[k][j][s+k-i])
                            || (f[i][k-1][s+(j-k+1)] && f[k][j][s]) || f[i][j][s];
                    }
                }
            }
        }
        return f[0][n-1][0];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.isScramble("great", "rgeat") << endl;
    cout << solver.isScramble("great", "rgtae") << endl;
    return 0;
}
