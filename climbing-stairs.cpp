#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int f[2] = {1, 1};

        for (int i = 2; i <= n; ++i) {
            f[0] = f[0] ^ f[1];
            f[1] = f[0] ^ f[1];
            f[0] = f[0] ^ f[1];

            f[1] += f[0];
        }

        return f[1];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.climbStairs(3) << endl;
    return 0;
}
