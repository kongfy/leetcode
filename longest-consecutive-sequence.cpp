#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        unordered_map<int, int> hash;
        int ans = 0;

        for (int i = 0; i < num.size(); ++i) {
            int n = num[i];

            if (hash.find(n) != hash.end()) continue;

            if (hash.find(n-1) == hash.end() && hash.find(n+1) == hash.end()) {
                hash[n] = 1;
                ans = max(ans, hash[n]);
            } else if (hash.find(n-1) == hash.end()) {
                int len = hash[n + 1];
                hash[n] = hash[n + len] = len + 1;
                ans = max(ans, hash[n]);
            } else if (hash.find(n+1) == hash.end()) {
                int len = hash[n - 1];
                hash[n] = hash[n - len] = len + 1;
                ans = max(ans, hash[n]);
            } else {
                int l = hash[n - 1];
                int r = hash[n + 1];
                hash[n - l] = hash[n + r] = l + r + 1;
                hash[n] = 1;
                ans = max(ans, hash[n - l]);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> num = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    Solution solver;
    cout << solver.longestConsecutive(num) << endl;
    return 0;
}
