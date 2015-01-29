#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > ans;

        int n = num.size();
        if (n < 3) {
            return ans;
        }

        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); ++i) {
            _set.insert(num[i]);
        }

        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 1; ++j) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }

                int t = -(num[i] + num[j]);
                if (t >= num[j] && _set.find(t) != _set.end()) {
                    if (t == num[j] && num[j + 1] != num[j]) {
                    } else {
                        ans.push_back({num[i], num[j], t});
                    }
                }
            }
        }

        return ans;
    }

private:
    unordered_set<int> _set;
};

int main(int argc, char *argv[])
{
    vector<int> S = {-1, 0, 1, 2, -1, -4};

    Solution solver;

    vector<vector<int> > ans = solver.threeSum(S);

    for (vector<int> &triplet : ans) {
        for (int &t : triplet) {
            cout << t << ' ';
        }
        cout << endl;
    }

    return 0;
}
