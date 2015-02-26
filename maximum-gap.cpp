#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &num)
    {
        int n = num.size();

        if (n < 2) {
            return 0;
        }

        sort(num.begin(), num.end());

        int gap = 0;
        for (int i = 1; i < n; ++i) {
            gap = max(gap, num[i] - num[i - 1]);
        }

        return gap;
    }
};
