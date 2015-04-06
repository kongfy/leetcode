#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0) return 0;

        stack<int> ts;
        int ans = 0;
        for (int  i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ts.push(i);
            } else if (s[i] == ')') {
                if (!ts.empty() && s[ts.top()] == '(') {
                    ts.pop();
                    int start = ts.empty() ? -1 : ts.top();
                    ans = max(ans, i - start );
                } else {
                    ts.push(i);
                }
            }
        }
        return ans;
    }
};
