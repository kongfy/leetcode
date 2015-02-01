#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string> > partition(string s)
    {
        int n = s.size();

        vector<vector<bool> > map(n, vector<bool> (n, false));
        for (int i = 0; i < n; ++i) {
            map[i][i] = true;
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (i == j - 1) {
                    map[i][j] = (s[i] == s[j]);
                } else {
                    map[i][j] = (map[i + 1][j - 1] && s[i] == s[j]);
                }
            }
        }

        vector<vector<string> > ans = subPartition(s, n, map);
        return ans;
    }

private:
    vector<vector<string> > subPartition(string &s, int n, vector<vector<bool> > &map)
    {
        vector<vector<string> > ans;

        if (map[0][n - 1]) {
            ans.push_back({s.substr(0, n)});
        }

        for (int i = 0; i < n - 1; ++i) {
            if (map[i + 1][n - 1]) {
                string st = s.substr(i + 1, n - i - 1);
                vector<vector<string> > temp = subPartition(s, i + 1, map);

                for (vector<string> &t : temp) {
                    t.push_back(st);
                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<vector<string> > ans = solver.partition("aab");

    for (vector<string> &temp : ans) {
        for (string &st : temp) {
            cout << st << " ";
        }
        cout << endl;
    }

    return 0;
}
