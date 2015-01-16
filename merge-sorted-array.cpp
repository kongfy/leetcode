class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int *temp = new int[m + n];

        int p = 0, q = 0;
        int t = 0;

        while (p < m && q < n) {
            if (A[p] < B[q]) {
                temp[t++] = A[p++];
            } else {
                temp[t++] = B[q++];
            }
        }

        while (p < m) {
            temp[t++] = A[p++];
        }

        while (q < n) {
            temp[t++] = B[q++];
        }

        for (int i = 0; i < m + n; ++i) {
            A[i] = temp[i];
        }
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
