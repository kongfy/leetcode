#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                return {l + 1, r + 1};
            }
        }

        return {0, 0};
    }
};

int main(int argc, char *argv[])
{
    vector<int> list = {2, 7, 11, 15};

    Solution solver;

    for (int index : solver.twoSum(list, 9)) {
        cout << index << endl;
    }

    return 0;
}
