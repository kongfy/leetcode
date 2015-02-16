#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());

        int n = S.size();
        vector<vector<int> > res;
        res.push_back(_temp); // empty subset

        dfs(S, res, 0, n);

        return res;
    }

private:
    vector<int> _temp;

    void dfs(vector<int> &S, vector<vector<int> > &res, int p, int n)
    {
        if (p == n) return;

        dfs(S, res, p + 1, n);

        _temp.push_back(S[p]);
        res.push_back(_temp);
        dfs(S, res, p + 1, n);
        _temp.pop_back();
    }
};

int main(int argc, char *argv[])
{
    vector<int> S = {1, 2, 3};
    vector<vector<int> > sub;

    Solution solver;

    sub = solver.subsets(S);

    for (vector<int> &s : sub) {
        for (int n : s) {
            cout << n << ' ';
        }
        cout << endl;
    }

    return 0;
}
