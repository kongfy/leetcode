#include <string>
#include <iostream>

using namespace std;


class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        int ls = s.size();
        int lt = t.size();

        if (abs(ls - lt) > 1) {
            return false;
        }

        int count = 0;

        if (ls == lt) {
            for (int i = 0; i < ls; ++i) {
                if (s[i] != t[i]) {
                    if (++ count > 1) {
                        return false;
                    }
                }
            }

            if (count == 1) {
                return true;
            }
        } else {
            if (ls > lt) {
                ls = ls ^ lt;
                lt = ls ^ lt;
                ls = ls ^ lt;

                string temp = s;
                s = t;
                t = temp;
            }

            int i = 0, j = 0;
            while (i < ls) {
                if (s[i] != t[j]) {
                    if (++ count > 1) {
                        return false;
                    }
                    j++;
                    continue;
                }
                i++;
                j++;
            }

            if (count <= 1) {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    string a("abcdefgh"), b("abcdefg");

    Solution solver;
    cout << solver.isOneEditDistance(a, b) << endl;
    return 0;
}
