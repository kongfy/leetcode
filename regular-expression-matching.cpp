#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        int n = strlen(p);
        int m = strlen(s);
        if (n == 0 && m != 0) return false;
        if (n == 0 && m == 0) return true;

        bool f[n + 1][m + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j != 0 && (p[i - 1] == '.' || p[i - 1] == s[j - 1])) {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[i - 1] == '*') {
                    f[i][j] = f[i - 2][j];
                    if (j != 0 && (p[i - 2] == '.' || s[j - 1] == p[i - 2])) {
                        f[i][j] |= f[i][j - 1] | f[i - 2][j - 1];
                    }
                }
            }
        }

        return f[n][m];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.isMatch("aa","a") << endl;
    cout << solver.isMatch("aa","aa") << endl;
    cout << solver.isMatch("aaa","aa") << endl;
    cout << solver.isMatch("aa", "a*") << endl;
    cout << solver.isMatch("aa", ".*") << endl;
    cout << solver.isMatch("ab", ".*") << endl;
    cout << solver.isMatch("aab", "c*a*b") << endl;
    cout << solver.isMatch("a", ".*..a*") << endl;
    cout << solver.isMatch("", "..*") << endl;

    return 0;
}
