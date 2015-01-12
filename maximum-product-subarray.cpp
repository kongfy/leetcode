#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProduct(int A[], int n)
    {
        int ans = A[0];
        int t1 = A[0], t2 = A[0];

        for (int i = 1; i < n; ++i) {
            int tt1 = max(t1 * A[i], A[i]);
            tt1 = max(tt1, t2 * A[i]);
            int tt2 = min(t2 * A[i], A[i]);
            tt2 = min(tt2, t1 * A[i]);

            t1 = tt1;
            t2 = tt2;

            ans = max(ans, t1);
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    int A[] = {-2, 3, -1, 4};
    cout << solver.maxProduct(A, 4) << endl;

    return 0;
}
