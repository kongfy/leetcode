#include <vector>
#include <iostream>

using namespace std;

// Don't like this solution...
const static int FLAG = (1 << 31) + 1;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        if (!matrix.size()) {
            return;
        }

        if (!matrix[0].size()) {
            return;
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) {
                    matrix[i][j] = FLAG;
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == FLAG) {
                    for (int k = 0; k < matrix.size(); ++k) {
                        if (matrix[k][j] != FLAG) {
                            matrix[k][j] = 0;
                        }
                    }

                    for (int k = 0; k < matrix[0].size(); ++k) {
                        if (matrix[i][k] != FLAG) {
                            matrix[i][k] = 0;
                        }
                    }
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    cout << FLAG << endl;
    return 0;
}
