#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n == 0) {
            return 0;
        }

        int ans = 0;
        int lowest = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            ans = max(prices[i] - lowest, ans);
            lowest = min(prices[i], lowest);
        }

        return ans;
    }
};


int main(int argc, char *argv[])
{

    return 0;
}
