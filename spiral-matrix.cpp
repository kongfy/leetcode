#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> ans;

        int count = 0;
        int n = matrix.size();

        if (n == 0) {
            return ans;
        }

        int m = matrix[0].size();

        while (true) {
            if (count >= n - count) {
                break;
            }
            for (int i = count; i < m - count; ++i) {
                ans.push_back(matrix[count][i]);
            }

            if (m - count - 1 <= count - 1) {
                break;
            }
            for (int i = count + 1; i < n - count; ++i) {
                ans.push_back(matrix[i][m - count - 1]);
            }

            if (n - count - 1 <= count) {
                break;
            }
            for (int i = m - count - 2; i >= count; --i) {
                ans.push_back(matrix[n - count - 1][i]);
            }

            if (count >= m - count - 1) {
                break;
            }
            for (int i = n - count - 2; i >= count + 1; --i) {
                ans.push_back(matrix[i][count]);
            }

            count ++;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    int width = 1;
    int height = 3;
    vector<vector<int> > matrix(height, vector<int>(width));

    int count = 1;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = count++;
        }
    }

    Solution solver;
    vector<int> ans = solver.spiralOrder(matrix);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
