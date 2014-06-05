#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        return getMaxArea(height, height.size());
    }

private:
    // The main function to find the maximum rectangular area under given
    // histogram with n bars
    // http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
    int getMaxArea(vector<int> &hist, int n)
    {
        // Create an empty stack. The stack holds indexes of hist[] array
        // The bars stored in stack are always in increasing order of their
        // heights.
        stack<int> s;

        int max_area = 0; // Initalize max area
        int tp;  // To store top of stack
        int area_with_top; // To store area with top bar as the smallest bar

        // Run through all bars of given histogram
        int i = 0;
        while (i < n)
        {
            // If this bar is higher than the bar on top stack, push it to stack
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);

            // If this bar is lower than top of stack, then calculate area of rectangle
            // with stack top as the smallest (or minimum height) bar. 'i' is
            // 'right index' for the top and element before top in stack is 'left index'
            else
            {
                tp = s.top();  // store the top index
                s.pop();  // pop the top

                // Calculate the area with hist[tp] stack as smallest bar
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                // update max area, if needed
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }

        // Now pop the remaining bars from stack and calculate area with every
        // popped bar as the smallest bar
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
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
