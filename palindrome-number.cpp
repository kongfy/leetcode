#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        int n = floor(log10(x));
        int base_l = pow(10, n);
        int base_r = 1;

        for (int i = 0; i < (n + 1) / 2; ++i) {
            int l = x / base_l % 10;
            int r = x / base_r % 10;

            if (l != r) {
                return false;
            }

            base_l /= 10;
            base_r *= 10;
        }

        return true;
    }
};


int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.isPalindrome(101) << endl;
    return 0;
}
