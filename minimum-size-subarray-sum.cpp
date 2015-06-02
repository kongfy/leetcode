#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int l = 0, r = 0;
        int sum = 0;
        int n = nums.size();
        if (!n) return 0;
        int ans = INT_MAX;

        while (r < n) {
            sum += nums[r];

            while (sum >= s && r >= l) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }

            r++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << solver.minSubArrayLen(7, nums) << endl;

    return 0;
}
