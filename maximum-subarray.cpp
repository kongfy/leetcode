class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        int ans = 1 << 31;
        int t = 0;

        for (int i = 0; i < n; ++i) {
            if (t < 0) {
                t = 0;
            }

            t += A[i];

            if (t > ans) {
                ans = t;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
