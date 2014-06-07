#include <cstdio>
#include <string>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int length = s.length();
        int max = 0;
        int temp = 0;
        int pair = 0;

        for (int i = 0; i < length; ++i) {
            temp++;

            if ('(' == s[i]) {
                if (pair < 0) {
                    pair = 0;
                    temp = 1;
                }

                pair++;
            }

            if (')' == s[i]) {
                pair--;

                if (0 == pair) {
                    if (temp > max) {
                        max = temp;
                    }
                }
            }
        }

        if (pair <= 0) {
            return max;
        }

        temp = 0;
        pair = 0;

        for (int i = length - 1; i != 0; --i) {
            temp++;

            if (')' == s[i]) {
                if (pair < 0) {
                    pair = 0;
                    temp = 1;
                }

                pair++;
            }

            if ('(' == s[i]) {
                pair--;

                if (0 == pair) {
                    if (temp > max) {
                        max = temp;
                    }
                }
            }
        }

        return max;
    }
};


int main(int argc, char *argv[])
{
    string str("()(()");

    Solution solution;
    int result = solution.longestValidParentheses(str);

    printf("%d\n", result);

    return 0;
}
