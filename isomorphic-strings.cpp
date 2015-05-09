#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> table;
        unordered_set<char> check;

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (table.find(s[i]) == table.end()) {
                if (check.find(t[i]) == check.end()) {
                    table[s[i]] = t[i];
                    check.insert(t[i]);
                } else {
                    return false;
                }
            } else {
                if (table[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};
