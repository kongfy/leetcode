#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int n = height.size();
        if (n == 0) return 0;

        stack<int> s;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!s.empty()) {
                while (!s.empty() && height[s.top()] > height[i]) {
                    int index = s.top();
                    int h = height[index];
                    s.pop();

                    int l = 0;
                    if (!s.empty()) {
                        l = s.top() + 1;
                    }

                    int area = h * (i - l);
                    ans = max(ans, area);
                }
            }

            s.push(i);
        }

        while (!s.empty()) {
            int index = s.top();
            int h = height[index];
            s.pop();
            int l = 0;
            if (!s.empty()) {
                l = s.top() + 1;
            }

            int area = h * (n - l);
            ans = max(ans, area);
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
