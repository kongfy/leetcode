#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        unordered_set<char> dict;
        unordered_map<char, int> count;
        for (int i = 0; i < T.size(); ++i) {
            dict.insert(T[i]);
            if (count.find(T[i]) != count.end()) {
                count[T[i]]++;
            } else {
                count[T[i]] = 1;
            }
        }

        int l = 0, r = 0;
        int n = S.size();
        int m = T.size();


        int len = n + 1;
        int s;

        while (r < n) {
            if (dict.find(S[r]) != dict.end()) {
                if (count[S[r]] > 0) {
                    m--;
                }
                count[S[r]]--;

                if (dict.find(S[l]) == dict.end() || count[S[l]] < 0) {
                    while (l < r) {
                        if (dict.find(S[l]) != dict.end()) {
                            if (count[S[l]] >= 0) break;
                            count[S[l]]++;
                        }
                        l++;
                    }
                }

                if (m == 0 && r - l + 1 < len) {
                    len = r - l + 1;
                    s = l;
                }
            }
            r++;
        }

        if (len > n) {
            return "";
        } else {
            return S.substr(s, len);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << solver.minWindow("aa", "aa") << endl;
    return 0;
}
