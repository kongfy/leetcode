#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n)
    {
        int bits[32];
        memset(bits, 0, sizeof bits);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                int mask = 1 << j;
                bits[j] += (A[i] & mask) ? 1 : 0;
            }
        }

        for (int i = 0; i < 32; ++i) {
            bits[i] %= 3;
        }

        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans |= bits[i] << i;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    int A[] = {1,1,1,2,2,2,4,4,4,-1};

    cout << solver.singleNumber(A, 10) << endl;

    return 0;
}
