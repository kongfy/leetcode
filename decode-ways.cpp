#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        if (n == 0) {
            return 0;
        }

        vector<int> f(n);

        if (n >= 1) {
            f[0] = isNum(s, 0, 1) ? 1 : 0;
        }

        if (n >= 2) {
            if (f[0] && isNum(s, 1, 1)) {
                f[1] += f[0];
            }
            if (isNum(s, 0, 2)) {
                f[1] += 1;
            }
        }

        for (int i = 2; i < n; ++i) {
            if (f[i - 2] && isNum(s, i - 1, 2)) {
                f[i] += f[i - 2];
            }
            if (f[i - 1] && isNum(s, i, 1)) {
                f[i] += f[i - 1];
            }
        }

        return f[n - 1];
    }

private:
    bool isNum(string &s, int start, int len)
    {
        if (s[start] == '0') {
            return false;
        }
        int num = stoi(s.substr(start, len));
        if (num >= 1 && num <= 26) {
            return true;
        }
        return false;
    }
};


int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.numDecodings("100") << endl;
    return 0;
}
