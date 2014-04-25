#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        if (s.empty()) {
            return true;
        }

        int length = s.length();
        bool *f = (bool *)malloc(length * sizeof(bool));
        memset(f, false, length * sizeof(bool));

        for (int i = 0; i < length; ++i) {
            string sub = s.substr(0, i + 1);
            if (dict.count(sub)) {
                f[i] = true;
                continue;
            }
            
            for (int j = 0; j < i; ++j) {
                if (f[j]) {
                    string sub = s.substr(j + 1, i - j);
                    if (dict.count(sub)) {
                        f[i] = true;
                    }
                }
            }
        }

        return f[length - 1];
    }
};

int main(int argc, char *argv[])
{
    string s("leetcode");
    unordered_set<string> dict;
    dict.insert(string("leet"));
    dict.insert(string("code"));
    
    Solution solution;
    bool ans = solution.wordBreak(s, dict);

    cout << ans << endl;
    
    return 0;
}

