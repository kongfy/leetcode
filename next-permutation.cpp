#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        int n = num.size();

        int i = 0;
        for (i = n - 1; i > 0; --i) {
            if (num[i] > num[i - 1]) {
                int t = i;
                while (t < n && num[t] > num[i - 1]) ++t;
                t--;
                num[i - 1] = num[t] ^ num[i - 1];
                num[t] = num[t] ^ num[i - 1];
                num[i - 1] = num[t] ^ num[i - 1];
                break;
            }
        }

        int l = i;
        int r = n - 1;
        // reverse the permutation
        while (l < r) {
            num[l] = num[l] ^ num[r];
            num[r] = num[l] ^ num[r];
            num[l] = num[l] ^ num[r];
            l++;
            r--;
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> num = {1,3,2};

    Solution solver;
    solver.nextPermutation(num);

    for (int t : num) {
        cout << t << ' ';
    }
    cout << endl;

    return 0;
}
