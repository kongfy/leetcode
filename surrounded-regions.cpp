#include <queue>
#include <iostream>

using namespace std;

class Solution
{
    void cleanUp(vector<vector<char> > &board)
    {
        for (vector<char> &row : board) {
            for (char &c : row) {
                if ('-' == c) {
                    c = 'O';
                } else if ('O' == c) {
                    c = 'X';
                }
            }
        }
    }

    inline bool inBoard(vector<vector<char> > &board, int x, int y)
    {
        int width = board[0].size();
        int height = board.size();

        if (x < 0 || x >= height || y < 0 || y >= width) {
            return false;
        }
        return true;
    }

    void color(vector<vector<char> > &board, int x, int y)
    {
        if ('O' != board[x][y]) {
            return;
        }

        board[x][y] = '-';

        xqueue.push(x);
        yqueue.push(y);

        while (!xqueue.empty()) {
            int tx = xqueue.front();
            int ty = yqueue.front();

            xqueue.pop();
            yqueue.pop();

            if (inBoard(board, tx + 1, ty) && board[tx + 1][ty] == 'O') {
                board[tx + 1][ty] = '-';
                xqueue.push(tx + 1);
                yqueue.push(ty);
            }

            if (inBoard(board, tx - 1, ty) && board[tx - 1][ty] == 'O') {
                board[tx - 1][ty] = '-';
                xqueue.push(tx - 1);
                yqueue.push(ty);
            }

            if (inBoard(board, tx, ty + 1) && board[tx][ty + 1] == 'O') {
                board[tx][ty + 1] = '-';
                xqueue.push(tx);
                yqueue.push(ty + 1);
            }

            if (inBoard(board, tx, ty - 1) && board[tx][ty - 1] == 'O') {
                board[tx][ty - 1] = '-';
                xqueue.push(tx);
                yqueue.push(ty - 1);
            }
        }
    }

    queue <int> xqueue, yqueue;

public:
    void solve(vector<vector<char> > &board)
    {
        if (!board.size()) {
            return;
        }

        int width = board[0].size();
        int height = board.size();

        for (int i = 0; i < width; ++i) {
            color(board, 0, i);
            color(board, height - 1, i);
        }

        for (int i = 0; i < height; ++i) {
            color(board, i, 0);
            color(board, i, width - 1);
        }

        cleanUp(board);
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    vector<char> row(6, 'X');
    vector<vector <char> > board(4, row);

    board[0][1] = board[0][3] = board[0][5] = 'O';
    board[1][0] = board[1][2] = board[1][4] = 'O';
    board[2][1] = board[2][3] = board[2][5] = 'O';
    board[3][0] = board[3][2] = board[3][4] = 'O';

    solve.solve(board);

    cout << endl;
    for (vector<char> &row : board) {
        for (char &c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}
