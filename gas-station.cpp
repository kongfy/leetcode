#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        vector<int> f(2 * n);

        for (int i = 0; i < n; ++i) {
            f[i] = f[n + i]  = gas[i] - cost[i];
        }

        int l = n;
        int r = l;
        int t = 0;

        while (r - l < n) {
            if (t + f[r] >= 0) {
                t += f[r++];
            } else {
                t += f[--l];
            }
        }

        if (t >= 0) {
            return l % n;
        } else {
            return -1;
        }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
