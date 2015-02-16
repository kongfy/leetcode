#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        int n = num.size();

        vector<vector<int> > res;
        vector<int> temp;
        vector<bool> check(n, false);

        if (n == 0) return res;
        dfs(num, temp, check, res, 0, n);
        return res;
    }

private:
    void dfs(vector<int> &num, vector<int> &temp, vector<bool> &check, vector<vector<int> > &res, int p, int n)
    {
        if (p == n) {
            res.push_back(temp);
            return;
        }

        int i = 0;
        while (i < n) {
            if (!check[i]) {
                check[i] = true;
                temp.push_back(num[i]);
                dfs(num, temp, check, res, p + 1, n);
                temp.pop_back();
                check[i] = false;

                int t = i;
                while (t < n && num[t] == num[i]) t++;
                i = t;
            } else {
                i++;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> num = {1, 1, 2};
    vector<vector<int> > res;

    Solution solver;
    res = solver.permuteUnique(num);

    for (vector<int> &p : res) {
        for (int n : p) {
            cout << n << ' ';
        }
        cout << endl;
    }

    return 0;
}
