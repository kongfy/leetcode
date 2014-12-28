#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int start = 0, len = 0;

        int *table = new int[256];
        for (int i = 0; i < 256; ++i) {
            table[i] = -1;
        }

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int index = table[c];

            if (index >= 0 && index >= start) {
                ans = max(ans, len);
                len -= index - start + 1;
                start = index + 1;
            }

            table[c] = i;
            len ++;
        }

        ans = max(ans, len);
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    string s0("abcabcbb");
    string s1("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
    string s2("hchzvfrkmlnozjk");
    string s3("qopubjguxhxdipfzwswybgfylqvjzhar");
    cout << solve.lengthOfLongestSubstring(s0) << endl;
    cout << solve.lengthOfLongestSubstring(s1) << endl;
    cout << solve.lengthOfLongestSubstring(s2) << endl;
    cout << solve.lengthOfLongestSubstring(s3) << endl;

    return 0;
}
