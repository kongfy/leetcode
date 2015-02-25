class Solution
{
public:
    void rotate(int nums[], int n, int k)
    {
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n - k);
    }

private:
    void reverse(int nums[], int s, int len)
    {
        int l = s;
        int r = s + len - 1;

        while (l < r) {
            nums[l] = nums[l] ^ nums[r];
            nums[r] = nums[l] ^ nums[r];
            nums[l] = nums[l] ^ nums[r];

            l++;
            r--;
        }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
