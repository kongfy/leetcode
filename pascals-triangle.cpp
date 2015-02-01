#include <vector>

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ans;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1);
            if (i == 0) {
                row[0] = 1;
            } else {
                for (int j = 1; j < i; ++j) {
                    row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
                row[0] = 1
                row[i] = 1;
            }
            ans.push_back(row);
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
