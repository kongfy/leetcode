#include <iostream>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if ((m + n) % 2) {
            return findK(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 + 1);
        } else {
            int a = findK(A, 0, m - 1, B, 0, n - 1, (m + n) / 2 + 1);
            int b = findK(A, 0, m - 1, B, 0, n - 1, (m + n) / 2);
            return (a + b) / 2.0;
        }
    }

private:
    int findK(int A[], int la, int ra, int B[], int lb, int rb, int k)
    {
        if (la > ra) {
            return B[lb + k - 1];
        }

        if (lb > rb) {
            return A[la + k - 1];
        }


        int mida = (la + ra) / 2;
        int midb = (lb + rb) / 2;
        int t = mida + 1 - la + midb + 1 - lb;

        if (A[mida] > B[midb]) {
            if (k > t) {
                return findK(A, la, ra, B, midb + 1, rb, k - (midb + 1 - lb));
            } else if (k < t) {
                return findK(A, la, mida - 1, B, lb, rb, k);
            } else {
                if (la == ra) {
                    return findK(A, la, ra, B, midb + 1, rb, k - (midb + 1 - lb));
                }
                return findK(A, la, mida, B, lb, rb, k);
            }
        } else {
            if (k > t) {
                return findK(A, mida + 1, ra, B, lb, rb, k - (mida + 1 - la));
            } else if (k < t) {
                return findK(A, la, ra, B, lb, midb - 1, k);
            } else {
                if (lb == rb) {
                    return findK(A, mida + 1, ra, B, lb, rb, k - (mida + 1 - la));
                }
                return findK(A, la, ra, B, lb, midb, k);
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
