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
        if (m > 30000) return false;
        if (n == 0 && m != 0) return false;
        if (n == 0 && m == 0) return true;
        if (m == 0) {
            for (int i = 0; i < n; ++i) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        vector<bool> f(m + 1, false);
        f[0] = true;

        for (int i = 1; i <= n; ++i) {
            vector<bool> t(m + 1, false);
            t[0] = p[i-1] == '*' && f[0];
            for (int j = 1; j <= m; ++j) {
                bool c1 = f[j - 1] && (p[i-1] == '?' || p[i-1] == '*' || p[i-1] == s[j-1]);
                bool c2 = (t[j - 1] || f[j]) && (p[i-1] == '*');
                t[j] = c1 || c2;
            }
            f = t;
        }
        return f[m];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.isMatch("aa","a") << endl;
    cout << solver.isMatch("aa","aa") << endl;
    cout << solver.isMatch("aaa","aa") << endl;
    cout << solver.isMatch("aa", "*") << endl;
    cout << solver.isMatch("aa", "a*") << endl;
    cout << solver.isMatch("ab", "?*") << endl;
    cout << solver.isMatch("aab", "c*a*b") << endl;
    cout << solver.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
    cout << solver.isMatch("", "*") << endl;
    cout << solver.isMatch("c", "*?*") << endl;

    return 0;
}
