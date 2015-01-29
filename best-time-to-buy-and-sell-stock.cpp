#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> lowest(prices.size());

        for (int i = 0; i < prices.size(); ++i) {
            if (i == 0) {
                lowest[i] = prices[i];
            } else {
                lowest[i] = min(prices[i], lowest[i - 1]);
            }
        }

        int ans = 0;

        for (int i = 1; i < prices.size(); ++i) {
            ans = max(prices[i] - lowest[i - 1], ans);
        }

        return ans;
    }
};


int main(int argc, char *argv[])
{

    return 0;
}
