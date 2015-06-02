#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<vector<int> > ans;
        vector<int> temp;

        dfs(k, n, 1, temp, ans);
        return ans;
    }

private:
    void dfs(int l, int b, int num, vector<int> &temp, vector<vector<int> > &ans)
    {
        if (l == 0 && b == 0) {
            ans.push_back(temp);
        }

        if (l == 0 || num > b || num > 9) return;

        for (int i = num; i <= 9; ++i) {
            temp.push_back(i);
            dfs(l - 1, b - i, i + 1, temp, ans);
            temp.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<vector<int> > ans = solver.combinationSum3(3, 9);
    for (vector<int> &tuple : ans) {
        for (int num : tuple) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
