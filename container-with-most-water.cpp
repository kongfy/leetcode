#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        if (n < 2) {
            return 0;
        }

        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]) {
                int i = l;
                while (i < r && height[i] <= height[l]) i++;
                l = i;
            } else {
                int i = r;
                while (i > l && height[i] <= height[r]) i--;
                r = i;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
