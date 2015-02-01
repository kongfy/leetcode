#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }

        int n = s3.size();
        int la = s1.size();
        int lb = s2.size();

        vector<vector<bool> > f(n + 1, vector<bool> (la, false));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= la; ++j) {
                f[i][j] = false;
            }
        }

        f[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= la; ++j) {
                int k = i - j;

                if (k < 0 || k > lb) {
                    continue;
                }

                if (j != 0 && s3[i - 1] == s1[j - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j - 1];
                }

                if (k != 0 && s3[i - 1] == s2[k - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j];
                }
            }
        }

        for (int i = 0; i <= la; ++i) {
            if (f[n][i]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << solver.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << solver.isInterleave("aabd", "abdc", "aabdbadc") << endl;

    return 0;
}
