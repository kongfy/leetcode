#include <iostream>

using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (A[mid] == target) {
                return mid;
            }

            if (A[mid] > A[l]) {
                if (target >= A[l] && target <= A[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target >= A[mid + 1] && target <= A[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }

        return A[l] == target ? l : -1;
    }
};

int main(int argc, char *argv[])
{
    int A[] = {3, 1};

    Solution solver;

    cout << solver.search(A, 2, 1) << endl;

    return 0;
}
