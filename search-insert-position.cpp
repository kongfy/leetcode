class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        int l = 0;
        int r = n;

        while (l < r) {
            int mid = (l + r) / 2;

            if (A[mid] == target) {
                return mid;
            }

            if (A[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
