#include <iostream>

using namespace std;

class Solution
{
public:
    int trap(int A[], int n)
    {
        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l < r && A[l] <= A[l + 1]) l++;
        while (l < r && A[r] <= A[r - 1]) r--;

        while (l < r) {
            int left = A[l];
            int right = A[r];

            if (A[l] < A[r]) {
                while (A[++l] < left) {
                    ans += left - A[l];
                }
            } else {
                while (A[--r] < right) {
                    ans += right - A[r];
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << solver.trap(A, 12) << endl;
    return 0;
}
