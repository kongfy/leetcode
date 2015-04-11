#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &num)
    {
        int n = num.size();
        if (!n) return 0;

        vector<int> f(n, 0);

        for (int i = 0; i < n; ++i) {
            f[i] = num[i];
            if (i > 0) {
                f[i] = max(f[i], f[i - 1]);
            }
            if (i > 1) {
                f[i] = max(f[i], f[i - 2] + num[i]);
            }
        }

        return f[n - 1];
    }
};
