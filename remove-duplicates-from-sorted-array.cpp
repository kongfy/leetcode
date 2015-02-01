#include <iostream>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        int i = 0;
        int t = 0;
        while (i < n) {
            int j = i;
            while (j < n && A[j] == A[i]) j++;
            A[t++] = A[i];
            i = j;
        }
        return t;
    }
};

int main(int argc, char *argv[])
{
    int A[] = {1,1,2};
    Solution solver;

    int len = solver.removeDuplicates(A, 4);
    for (int i = 0; i < len; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;

    return 0;
}
