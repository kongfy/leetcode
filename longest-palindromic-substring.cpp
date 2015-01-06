#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0) {
            return 0;
        }

        int n = s.size();

        vector<int> f(n);

        int len = 1;
        int start = 0;
        for (int i = n - 1; i >= 0; --i) {
            f[i] = 1;
            for (int j = n - 1; j > i; --j) {

                if (i == j - 1) {
                    if (s[i] == s[j]) {
                        f[j] = 2;
                        if (len < f[j]) {
                            len = f[j];
                            start = i;
                        }
                    } else {
                        f[j] = 0;
                    }
                    continue;
                }

                if (f[j - 1] > 0) {
                    if (s[i] == s[j]) {
                        f[j] = f[j - 1] + 2;
                        if (len < f[j]) {
                            len = f[j];
                            start = i;
                        }
                    } else {
                        f[j] = 0;
                    }
                } else {

                    f[j] = 0;
                }
            }
        }

        return s.substr(start, len);
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    string s("ccc");
    cout << solver.longestPalindrome(s) << endl;

    return 0;
}
