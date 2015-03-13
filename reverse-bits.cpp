#include <iostream>

using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans |= n & 1;
            n >>= 1;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    uint32_t n = 43261596;

    Solution solver;
    cout << solver.reverseBits(n) << endl;

    return 0;
}
