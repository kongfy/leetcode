#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int jump(int A[], int n)
    {
        int left = 0, right = 0;
        int step = 0;

        while (right < n - 1 && left <= right) {
            int temp = 0;
            for (int i = left; i <= right; ++i) {
                if (A[i] + i > temp) {
                    temp = A[i] + i;
                }
            }

            left = right + 1;
            right = temp;

            step++;
        }

        return step;
    }
};

int main(int argc, char *argv[])
{
    int A[] = {2, 3, 1, 1, 4};

    Solution solver;
    cout << solver.jump(A, 5) << endl;

    return 0;
}
