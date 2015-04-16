#include <iostream>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        for (int i = 0; i < 31; ++i) {
            int mask = ~(1 << i);
            int t = n & mask;

            if (t <= n && t >= m) {
                m &= mask;
            }
        }

        return m;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
