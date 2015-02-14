#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
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
        int i = p;
        while (i < n) {
            if (sum + candidates[i] > target) {
                break;
            }

            _temp.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], res, target);
            _temp.pop_back();

            i++;
            while (i < n && candidates[i] == candidates[i-1]) i++;
        }
    }

    vector<int> _temp;
};

int main(int argc, char *argv[])
{

    return 0;
}
