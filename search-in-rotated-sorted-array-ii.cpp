#include <iostream>

using namespace std;

class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (A[mid] == target) {
                return true;
            }

            if (A[mid] > A[l]) {
                if (target >= A[l] && target <= A[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (A[mid] < A[l]) {
                if (target >= A[mid + 1] && target <= A[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            } else {
                l++;
            }
        }

        return A[l] == target;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
