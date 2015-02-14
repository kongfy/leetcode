#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int> > res;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, res, target);

        return res;
    }

private:
    void dfs(vector<int> &candidates, int p, int sum, vector<vector<int> > &res, int target)
    {
        if (sum == target) {
            res.push_back(_temp);
            return;
        }

        int n = candidates.size();
        for (int i = p; i < n; ++i) {
            if (sum + candidates[i] > target) {
                break;
            }

            int t = 0;
            while (sum + candidates[i] * (t + 1) <= target) {
                t++;
                _temp.push_back(candidates[i]);
                dfs(candidates, i + 1, sum + candidates[i] * t, res, target);
            }

            while (t > 0) {
                _temp.pop_back();
                t--;
            }
        }
    }

    vector<int> _temp;
};

int main(int argc, char *argv[])
{

    return 0;
}
