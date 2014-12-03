#include <iostream>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int flag = 1;
        unsigned int udividend = dividend, udivisor = divisor;
        if (dividend < 0) {
            udividend = -dividend;
            flag = -flag;
        }
        if (divisor < 0) {
            udivisor = -divisor;
            flag = -flag;
        }

        int ans = 0;
        unsigned int r = udividend;

        while (r >= udivisor) {
            unsigned int c = 1;
            unsigned int t = udivisor;

            while ((t << 1) > 0 && (t << 1) <= r) {
                t <<= 1;
                c <<= 1;
            }

            ans += c;
            r -= t;
        }

        return flag * ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    cout << solve.divide(1, -1) << endl;

    return 0;
}
