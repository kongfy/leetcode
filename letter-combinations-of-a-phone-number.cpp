#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        dfs(digits, 0, "", ans);
        return ans;
    }
private:
    void dfs(string &digits, int n, string current, vector<string> &ans)
    {
        if (n == digits.size()) {
            ans.push_back(current);
            return;
        }

        int d = digits[n] - '0';

        if (d == 0) {
            dfs(digits, n + 1, current + ' ', ans);
        } else if (d == 1) {
            dfs(digits, n + 1, current, ans);
        } else if (d == 7 || d == 9) {
            char s = d == 7 ? 'p' : 'w';
            for (int i = 0; i < 4; ++i) {
                dfs(digits, n + 1, current + (char)(s + i), ans);
            }
        } else {
            char s = d == 8 ? 't' : ('a' + 3 * (d - 2));
            for (int i = 0; i < 3; ++i) {
                dfs(digits, n + 1, current + (char)(s + i), ans);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<string> ans = solver.letterCombinations("23");

    for (string &s : ans) {
        cout << s << endl;
    }

    return 0;
}
