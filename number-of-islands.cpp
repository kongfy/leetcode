#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;

        vector<vector<int> > map(n, vector<int> (m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                map[i][j] = -(grid[i][j] - '0');
            }
        }

        int island = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == -1) {
                    color(map, i, j, ++island);
                }
            }
        }

        return island;
    }

private:
    void color(vector<vector<int> > &map, int x, int y, int num)
    {
        int n = map.size();
        int m = map[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (map[x][y] != -1) return;

        map[x][y] = num;

        color(map, x - 1, y, num);
        color(map, x + 1, y, num);
        color(map, x, y - 1, num);
        color(map, x, y + 1, num);
    }
};
