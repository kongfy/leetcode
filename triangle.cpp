#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        if (triangle.size() <= 0) {
            return 0;
        }

        // dp
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

int main(int argc, char *argv[])
{
    vector<int> row0 = {2};
    vector<int> row1 = {3, 4};
    vector<int> row2 = {6, 5, 7};
    vector<int> row3 = {4, 1, 8, 3};

    vector<vector<int> > triangle = {row0, row1, row2, row3};

    Solution solver;
    cout << solver.minimumTotal(triangle) << endl;

    return 0;
}
