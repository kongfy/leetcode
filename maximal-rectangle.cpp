#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

static const int ZERO = -1000000;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        int n = matrix.size();

        if (!n) {
            return 0;
        }

        int m = matrix[0].size();

        if (!m) {
            return 0;
        }

        vector<vector<int> > map(n, vector<int>(m)), temp(n, vector<int>(m));

        this->_max = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ('0' == matrix[i][j]) {
                    map[i][j] = ZERO;
                } else {
                    map[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int t = map[i][j];

                if (i > 0) {
                    t += temp[i-1][j];
                }
                temp[i][j] = t;
            }
        }

        int f[m];

        for (int i = 0; i < n; ++i) {
            memset(f, 0, sizeof f);
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    f[k] = (i == 0 ? temp[j][k] : temp[j][k] - temp[i-1][k]);
                }

                int t  = maximalSubRange(f, m);
                if (t > this->_max) {
                    this->_max = t;
                }
            }
        }

        return this->_max;
    }

private:
    int _max;

    int maximalSubRange(int f[], int n) {
        int max = 0;

        if (f[0] > max) {
            max = f[0];
        }

        for (int i = 1; i < n; ++i) {
            if (f[i - 1] > 0) {
                f[i] += f[i - 1];
            }
            if (f[i] > max) {
                max = f[i];
            }
        }

        return max;
    }
};

int main(int argc, char *argv[])
{
    vector<char> row(4, '1');
    vector<vector<char> >matrix(4, row);

    matrix[0][0] = '0';
    matrix[0][3] = '0';
    matrix[1][0] = '0';
    matrix[2][3] = '0';
    matrix[3][1] = '0';

    Solution solver;
    cout << solver.maximalRectangle(matrix) << endl;

    return 0;
}
