#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int findPeakElement(const vector<int> &num)
    {
        int l = 0;
        int r = num.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (isPeak(num, mid)) {
                return mid;
            }

            if ((mid == 0 || num[mid] > num[mid - 1]) && (num[mid] < num[mid + 1])) {
                l = mid + 1;
            } else if ((mid == 0 || num[mid] < num[mid - 1]) && (num[mid] > num[mid + 1])) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool isPeak(const vector<int> &num, int index)
    {
        if (num.size() == 1) {
            return true;
        }

        if (index == 0) {
            return num[index] > num[index + 1];
        }

        if (index == num.size() - 1) {
            return num[index] > num[index - 1];
        }

        return num[index] > num[index + 1] && num[index] > num[index - 1];
    }
};

int main(int argc, char *argv[])
{
    vector<int> num = {1, 2, 3, 1};
    Solution solver;
    cout << solver.findPeakElement(num) << endl;
    return 0;
}
