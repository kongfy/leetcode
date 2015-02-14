#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int nRows)
    {
        string ans;
        int n = s.size();
        int step = nRows > 1 ? 2 * nRows - 2 : 1;

        for (int r = 0; r < nRows; ++r) {
            int p = r;
            int mstep = step - r * 2;

            while (p < n) {
                ans = ans + s[p];

                if (mstep != step && mstep != 0) {
                    int mid = p + mstep;
                    if (mid < n) {
                        ans = ans + s[mid];
                    }
                }

                p += step;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.convert("PAYPALISHIRING", 3) << endl;
    cout << solver.convert("A", 1) << endl;
    return 0;
}
