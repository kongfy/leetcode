class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1) {
            return 0;
        }

        int t = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > t) {
                profit += prices[i] - t;

            }
            t = prices[i];
        }

        return profit;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
