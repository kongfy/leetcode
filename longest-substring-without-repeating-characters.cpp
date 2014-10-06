#include <string>
#include <iostream>

using namespace std;

class Solution
{
    int _table[256];

    void mark(char c, int index)
    {
        _table[c] = index;
    }

    int check(char c)
    {
        return _table[c];
    }

    void clear()
    {
        for (int i = 0; i < 256; ++i) {
            _table[i] = -1;
        }
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int start = 0, len = 0;

        clear();
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            int index = check(c);
            if (index >= 0) {
                ans = max(ans, len);

                for (int j = start; j <= index; ++j) {
                    mark(s[j], -1);
                }

                len -= index - start + 1;
                start = index + 1;
            }

            mark(c, i);
            len ++;
        }

        ans = max(ans, len);
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    string s1("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    string s2("hchzvfrkmlnozjk");
    string s3("qopubjguxhxdipfzwswybgfylqvjzhar");
    cout << solve.lengthOfLongestSubstring(s1) << endl;
    cout << solve.lengthOfLongestSubstring(s2) << endl;
    cout << solve.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
