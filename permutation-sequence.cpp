#include <string>
#include <iostream>
#include <cstring>


using namespace std;

class Solution
{
    int factorial(int n)
    {
        if (1 == n) {
            return 1;
        };

        return n * factorial(n - 1);
    }

    bool _check[9];

    int minimal(int n, int k)
    {
        for (int i = 0; i < n; i++) {
            if (!_check[i]) {
                if (!k) {
                    _check[i] = true;
                    return i + 1;
                } else {
                    k--;
                }
            }
        }
        return 0;
    }

public:
    string getPermutation(int n, int k)
    {
        memset(_check, false, sizeof _check);

        string permutation;

        for (int i = 0; i < n; i++) {
            int num = 0;

            if (i == n - 1) {
                num = minimal(n, 0);
            } else {
                int m = factorial(n - i - 1);
                int index = (k-1) / m;
                num = minimal(n, index);

                k -= index * m;
            }

            permutation += '0' + num;
        }

        return permutation;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    for (int i = 1; i <= 24; ++i) {
        cout << solve.getPermutation(4, i) << endl;
    }

    return 0;
}
