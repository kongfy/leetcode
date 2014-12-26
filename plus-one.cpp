#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int t = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += t;
            t = digits[i] / 10;
            digits[i] %= 10;
        }

        if (t) {
            digits.insert(digits.begin(), t);
        }

        return digits;
    }
};

int main(int argc, char *argv[])
{
    vector<int> digits = {9, 9};

    Solution solver;
    vector<int> ans = solver.plusOne(digits);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
