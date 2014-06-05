#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        return maxArea(height, 0, height.size());
    }

private:
    int maxArea(vector<int> &height, int l, int r)
    {
        if (l >= r) {
            return 0;
        }

        int min = height[l];
        int index = l;

        if (l >= r) {
            return 0;
        }

        for (int i = l; i < r; ++i) {
            if (height[i] < min) {
                min = height[i];
                index = i;
            }
        }

        int left = maxArea(height, l, index);
        int right = maxArea(height, index + 1, r);
        int ans = (r - l) * min;

        if (left > ans) {
            ans = left;
        }

        if (right > ans) {
            ans = right;
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);

    Solution solution;
    int result = solution.largestRectangleArea(height);

    printf("%d\n", result);

    return 0;
}
