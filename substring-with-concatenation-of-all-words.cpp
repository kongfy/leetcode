#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        int n = S.size();
        int m = L.size();
        int len = L[0].size();
        vector<int> ans;

        if (n == 0 || m == 0) return ans;

        unordered_map<string, int> dict;
        for (int i = 0; i < m; ++i) {
            dict[L[i]]++;
        }

        for (int i = 0; i < len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> hash;

            for (int j = i; j <= n - len; j += len) {
                string str = S.substr(j, len);

                if (dict.count(str)) {
                    hash[str]++;
                    if (hash[str] <= dict[str]) {
                        count++;
                    } else {
                        while (hash[str] > dict[str]) {
                            string str1 = S.substr(left, len);
                            hash[str1]--;
                            if (hash[str1] < dict[str1]) count--;
                            left += len;
                        }
                    }

                    if (count == m) {
                        ans.push_back(left);
                    }
                } else {
                    hash.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    string S("barfoothefoobarman");
    vector<string> L = {"foo", "bar"};

    Solution solver;
    vector<int> indices = solver.findSubstring(S, L);

    for (int i = 0; i < indices.size(); ++i) {
        cout << indices[i] << endl;
    }

    return 0;
}
