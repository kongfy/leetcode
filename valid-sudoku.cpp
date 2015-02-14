#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        for (int i = 0; i < 9; ++i) {
            if (!checkRow(board, i)) return false;
            if (!checkColumn(board, i)) return false;
            if (!checkBlock(board, i)) return false;
        }

        return true;
    }

private:
    bool checkNine(vector<char> &array)
    {
        vector<bool> check(9, false);
        for (int i = 0; i < 9; ++i) {
            char c = array[i];
            if (c == '.') {
                continue;
            }

            if (c < '0' || c > '9') {
                return false;
            }

            if (check[c - '0']) {
                return false;
            } else {
                check[c - '0'] = true;
            }
        }
        return true;
    }

    bool checkRow(vector<vector<char> > &board, int row)
    {
        return checkNine(board[row]);
    }

    bool checkColumn(vector<vector<char> > &board, int column)
    {
        vector<char> temp(9);
        for (int i = 0; i < 9; ++i) {
            temp[i] = board[i][column];
        }
        return checkNine(temp);
    }

    bool checkBlock(vector<vector<char> > &board, int block)
    {
        int x = block / 3;
        int y = block % 3;

        x *= 3;
        y *= 3;

        vector<char> temp(9);
        int i = 0;
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                temp[i++] = board[x + m][y + n];
            }
        }

        return checkNine(temp);
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
