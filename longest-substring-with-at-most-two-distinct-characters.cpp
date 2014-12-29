#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if (s.size() <= 2) {
            return s.size();
        }

        char a, b;
        int ra, rb;
        a = s[0];
        ra = 0;

        int i = 1;
        while (i < s.size() && s[i] == a) {
            ra = i;
            i++;
        }

        b = s[i];
        rb = i;

        int l = 0;
        int length = 0;
        for (; i < s.size(); ++i) {
            if (s[i] != a && s[i] != b) {
                length = max(length, i - l);

                if (s[i - 1] == a) {
                    l = rb + 1;
                } else if (s[i - 1] == b) {
                    l = ra + 1;
                } else {
                    assert(false);
                }

                a = s[i - 1];
                ra = i - 1;
                b = s[i];
                rb = i;
            } else if (s[i] == a) {
                ra = i;
            } else if (s[i] == b) {
                rb = i;
            }
        }

        length = max(length, i - l);
        return length;
    }
};

int main(int argc, char *argv[])
{
    string s("cdaba");

    Solution solver;
    cout << solver.lengthOfLongestSubstringTwoDistinct(s) << endl;

    return 0;
}
