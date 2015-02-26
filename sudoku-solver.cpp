#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char> > &board)
    {
        vector<vector<bool> > row(9, vector<bool> (9, false));
        vector<vector<bool> > column(9, vector<bool> (9, false));
        vector<vector<bool> > block(9, vector<bool> (9, false));

        int num = initCheck(board, row, column, block);
        dfs(board, row, column, block, num);
    }

private:
    int initCheck(vector<vector<char> > &board, vector<vector<bool> > &row, vector<vector<bool> > &column, vector<vector<bool> > &block)
    {
        int count = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = true;
                    column[j][t] = true;
                    block[i/3 * 3 + j / 3][t] = true;
                    count++;
                }
            }
        }
        return count;
    }

    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &row, vector<vector<bool> > &column, vector<vector<bool> > &block, int dep)
    {
        if (dep == 81) {
            return true;
        }

        int x, y;
        for (x = 0; x < 9; ++x) {
            for (y = 0; y < 9; ++y) {
                if (board[x][y] == '.') break;
            }
            if (board[x][y] == '.') break;
        }

        for (int i = 0; i < 9; ++i) {
            if (!row[x][i] && !column[y][i] && !block[x/3 * 3 + y / 3][i]) {
                board[x][y] = '1' + i;
                row[x][i] = true;
                column[y][i] = true;
                block[x/3 * 3 + y / 3][i] = true;

                if (dfs(board, row, column, block, dep + 1)) return true;

                board[x][y] = '.';
                row[x][i] = false;
                column[y][i] = false;
                block[x/3 * 3 + y / 3][i] = false;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char> > board(9);
    board[0] = {'5','3','.','.','7','.','.','.','.'};
    board[1] = {'6','.','.','1','9','5','.','.','.'};
    board[2] = {'.','9','8','.','.','.','.','6','.'};
    board[3] = {'8','.','.','.','6','.','.','.','3'};
    board[4] = {'4','.','.','8','.','3','.','.','1'};
    board[5] = {'7','.','.','.','2','.','.','.','6'};
    board[6] = {'.','6','.','.','.','.','2','8','.'};
    board[7] = {'.','.','.','4','1','9','.','.','5'};
    board[8] = {'.','.','.','.','8','.','.','7','9'};

    Solution solver;
    solver.solveSudoku(board);

    for (vector<char> &row : board) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}
