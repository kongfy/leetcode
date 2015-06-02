#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return findKthLargestSub(nums, 0, nums.size(), nums.size() - k + 1);
    }

private:
    int findKthLargestSub(vector<int> &nums, int start, int len, int k)
    {
        int pivot = nums[start];

        int index = start + 1;
        for (int i = start + 1; i < start + len; ++i) {
            if (nums[i] < pivot) {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                index++;
            }
        }

        nums[start] = nums[index - 1];
        nums[index - 1] = pivot;

        int order = index - start;
        if (order == k) {
            return pivot;
        } else if (order < k) {
            return findKthLargestSub(nums, index, len - order, k - order);
        } else {
            return findKthLargestSub(nums, start, order - 1, k);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<int> nums = {3, 2, 1, 5, 6, 4};

    for (int i = 1; i <= nums.size(); ++i) {
        cout << solver.findKthLargest(nums, i) << endl;
    }

    return 0;
}
