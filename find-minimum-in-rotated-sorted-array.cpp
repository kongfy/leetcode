class Solution
{
public:
    int findMin(vector<int> &num)
    {
        int l = 0;
        int r = num.size() - 1;

        while (l < r && num[l] >= num[r]) {
            int mid = (l + r) / 2;

            if (num[mid] >= num[l]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return num[l];
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
