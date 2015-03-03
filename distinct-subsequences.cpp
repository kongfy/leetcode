#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numDistinct(string S, string T)
    {
        int n = T.size();
        int m = S.size();

        if (!n || !m) {
            return 0;
        }

        int f[2][m];
        memset(f, 0, sizeof(int) * 2 * m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > j) {
                    f[i % 2][j] = 0;
                } else {
                    if (j > 0) {
                        f[i % 2][j] = f[i % 2][j - 1];
                    }
                    if (T[i] == S[j]) {
                        if (i == 0 || j == 0) {
                            f[i % 2][j] += 1;
                        } else {
                            f[i % 2][j] += f[(i-1) % 2][j - 1];
                        }
                    }
                }
            }
        }

        return f[(n-1) % 2][m - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.numDistinct("rabbbit", "rabbit") << endl;;
    return 0;
}
