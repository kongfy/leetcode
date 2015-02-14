class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int i = 0, l = 0, r = n - 1;

        while (i <= r) {
            if (A[i] == 0) {
                A[i++] = A[l];
                A[l++] = 0;
            } else if (A[i] == 2) {
                A[i] = A[r];
                A[r--] = 2;
            } else {
                i++;
            }
        }
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
