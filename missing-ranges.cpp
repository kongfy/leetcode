#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper)
    {
        vector<string> ranges;

        for (int i = 0; i < n; ++i) {

            if (A[i] == lower) {
                lower++;
                continue;
            }

            if (A[i] > lower) {
                ranges.push_back(range(lower, A[i] - 1));
                lower = A[i] + 1;
            }
        }

        if (lower <= upper) {
            ranges.push_back(range(lower, upper));
        }

        return ranges;
    }

private:
    string range(int l, int r)
    {
        string str;

        if (l == r) {
            str = to_string(l);
        } else {
            str = to_string(l) + "->" + to_string(r);
        }

        return str;
    }
};

int main(int argc, char *argv[])
{
    int A[] = {1, 3, 50, 75};

    Solution solver;
    vector<string> ans;

    ans = solver.findMissingRanges(A, 4, 0, 99);

    for (string &s : ans) {
        cout << s << endl;
    }

    return 0;
}
