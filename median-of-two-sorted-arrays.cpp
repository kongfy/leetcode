#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        int t = m + n;
        if (t & 1) {
            return findKth(A, m, B, n, t / 2 + 1);
        } else {
            int a = findKth(A, m, B, n, t / 2);
            int b = findKth(A, m, B, n, t / 2 + 1);
            return (a + b) / 2.0;
        }
    }

private:
    int findKth(int A[], int m, int B[], int n, int k)
    {
        if (m  == 0) {
            return B[k - 1];
        }

        if (n == 0) {
            return A[k - 1];
        }

        int mid_a = (m-1) / 2;
        int mid_b = (n-1) / 2;

        if (mid_a + 1 + mid_b + 1 <= k) {
            if (mid_a + 1 + mid_b + 1 == k && A[mid_a] == B[mid_b]) {
                return max(A[mid_a], B[mid_b]);
            }

            if (A[mid_a] > B[mid_b]) {
                return findKth(A, m, B + mid_b + 1, n - mid_b - 1, k - mid_b - 1);
            } else {
                return findKth(A + mid_a + 1, m - mid_a - 1, B, n, k - mid_a - 1);
            }
        } else if (mid_a + 1 + mid_b + 1 > k) {
            if (A[mid_a] > B[mid_b]) {
                return findKth(A, mid_a, B, n, k);
            } else {
                return findKth(A, m, B, mid_b, k);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    int A[] = {1,3,5};
    int B[] = {0,2,4,6,8,10};

    cout << solver.findMedianSortedArrays(A, 2, B, 0) << endl;
    return 0;
}
