#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int> > f(3, vector<int> (n, 0));

        int ans = 0;
        for (int m = 1; m <= 2; m++) {
            int tmp = f[m - 1][0] - prices[0];
            for (int i = 1; i < n; ++i) {
                f[m][i] = max(f[m][i - 1], prices[i] + tmp);
                tmp = max(tmp, f[m - 1][i] - prices[i]);
                ans = max(ans, f[m][i]);
            }
        }

        return ans;

    }
};

int main(int argc, char *argv[])
{

    return 0;
}
