#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;

        dfs(n, n, res, "");

        return res;
    }

private:
    void dfs(int left, int right, vector<string> &res, string str)
    {
        if (left == 0 && right == 0) {
            // push
            res.push_back(str);
            return;
        }

        if (left) {
            dfs(left - 1, right, res, str + '(');
        }

        if (right && right > left) {
            dfs(left, right - 1, res, str + ')');
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<string> res = solver.generateParenthesis(3);
    for (string &str : res) {
        cout << str << endl;
    }

    return 0;
}
