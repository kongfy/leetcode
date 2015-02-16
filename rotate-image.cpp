#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n/2; ++i) {
            int l = n/2;
            if (n % 2) l++;

            for (int j = 0; j < l; ++j)
            {
                swap(matrix[i][j], matrix[j][n - 1 - i]);
                swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
                swap(matrix[i][j], matrix[n - 1 - j][i]);
            }
        }
    }

    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main(int argc, char *argv[])
{


    return 0;
}
