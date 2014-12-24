#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !isCharOrDigit(s[l])) {
                l++;
            }

            while (l < r && !isCharOrDigit(s[r])) {
                r--;
            }

            if (toLowerCase(s[l]) == toLowerCase(s[r])) {
                l++;
                r--;
            } else {
                return false;
            }
        }

        return true;
    }

private:
    inline bool isCharOrDigit(char c)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    inline char toLowerCase(char c)
    {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        }

        return c;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    string str("`l;`` 1o1 ??;l`");

    cout << solver.isPalindrome(str) << endl;

    return 0;
}
