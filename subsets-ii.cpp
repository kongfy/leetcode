#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
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

        int i = p;
        while (i < n) {
            _temp.push_back(S[i]);
            res.push_back(_temp);
            dfs(S, res, i + 1, n);
            _temp.pop_back();

            int t = i;
            while (t < n && S[t] == S[i]) t++;
            i = t;
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> S = {1, 2, 2};
    vector<vector<int> > sub;

    Solution solver;

    sub = solver.subsetsWithDup(S);

    for (vector<int> &s : sub) {
        for (int n : s) {
            cout << n << ' ';
        }
        cout << endl;
    }

    return 0;
}
