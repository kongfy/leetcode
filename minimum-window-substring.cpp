#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        unordered_map<char, int> dict;

        int m = T.size();
        int total = m;
        for (int i = 0; i < m; ++i) {
            if (dict.find(T[i]) == dict.end()) {
                dict[T[i]] = 1;
            } else {
                dict[T[i]]++;
            }
        }

        int len = INT_MAX;
        int n = S.size();

        int l = 0, r = 0;
        int temp_l = 0;
        while (l < n && dict.find(S[l]) == dict.end()) l++;
        r = l;
        while (r < n) {
            if (dict.find(S[r]) != dict.end()) {
                if (dict[S[r]] > 0) total--;
                dict[S[r]]--;

                while (dict.find(S[l]) == dict.end() || dict[S[l]] <0) {
                    if (dict.find(S[l]) != dict.end()) {
                        dict[S[l]]++;
                    }
                    l++;
                }

                if (total == 0) {
                    int t = r - l + 1;
                    if (t < len) {
                        temp_l = l;
                        len = t;
                    }
                }
            }

            r++;
        }

        if (len == INT_MAX) return "";
        return S.substr(temp_l, len);
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << solver.minWindow("aa", "aa") << endl;
    return 0;
}
