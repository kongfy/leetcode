#include<iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        int last = n - 1;
        int i = 0;
        while (i < last) {
            while (A[i] == elem & i < last) {
                swap(A, i, last--);
            }
            ++i;
        }

        if (A[last] == elem) {
            return last;
        }
        return last + 1;
    }

private:
    inline void swap(int A[], int i, int j)
    {
        if (i == j) {
            return;
        }

        A[i] = A[i] ^ A[j];
        A[j] = A[i] ^ A[j];
        A[i] = A[i] ^ A[j];
    }
};

int main(int argc, char *argv[])
{
    int A[] = {1,1,2,1,1};
    Solution solver;

    cout << solver.removeElement(A, 5, 1) << endl;
    return 0;
}
