#include <vector>
#include <iostream>


using namespace std;

class Solution
{
    vector<int> &targetRow(vector<vector<int> > &matrix, int target, int l, int r)
    {
        if (l == r) {
            return matrix[l];
        }

        int mid = (l + r) / 2;
        int temp = matrix[mid].front();

        int len = matrix[mid].size();
        if (target >= temp && target <= matrix[mid][len - 1]) {
            return matrix[mid];
        }

        if (target < temp) {
            return targetRow(matrix, target, l, max(mid - 1, l));
        } else {
            return targetRow(matrix, target, min(mid + 1, r), r);
        }
    }

    bool searchRow(vector<int> &row, int target)
    {
        if (target < row.front() || target > row[row.size() - 1]) {
            return false;
        }

        int l = 0;
        int r = row.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int temp = row[mid];

            if (target == temp) {
                return true;
            }

            if (target < temp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (!matrix.size()) {
            return false;
        }

        vector<int> &row = targetRow(matrix, target, 0, matrix.size() - 1);
        return searchRow(row, target);
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    vector<int> row0 {1,3,5,7};
    vector<int> row1 {10,11,16,20};
    vector<int> row2 {23,30,34,50};

    vector<vector<int> > matrix {row0, row1, row2};

    cout << solve.searchMatrix(matrix, 20) << endl;

    return 0;
}
