#include <stdio.h>

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                swap(A, n, i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

private:
    void swap(int A[], int n, int index)
    {
        int temp = A[index];
        A[index] = 0;
        while (temp > 0 && temp <= n && A[temp - 1] != temp) {
            int t = temp;
            temp = A[temp - 1];
            A[t - 1] = t;
        }
    }
};

int main(int argc, char *argv[])
{
    int a[6] = {-1, 4, 2, 1, 9, 10};

    Solution solution;
    int ans = solution.firstMissingPositive(a, 6);

    printf("%d\n", ans);
    
    return 0;
}
