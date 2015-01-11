#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > matrix(n, vector<int>(n));

        if (n == 0) {
            return matrix;
        }

        int count = 0;
        int num = 1;

        while (true) {
            if (count >= n - count) {
                break;
            }
            for (int i = count; i < n - count; ++i) {
                matrix[count][i] = num++;
            }

            if (n - count - 1 <= count - 1) {
                break;
            }
            for (int i = count + 1; i < n - count; ++i) {
                matrix[i][n - count - 1] = num++;
            }

            if (n - count - 1 <= count) {
                break;
            }
            for (int i = n - count - 2; i >= count; --i) {
                matrix[n - count - 1][i] = num++;
            }

            if (count >= n - count - 1) {
                break;
            }
            for (int i = n - count - 2; i >= count + 1; --i) {
                matrix[i][count] = num++;
            }

            count ++;
        }

        return matrix;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
