#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int l1 = version1.size();
        int l2 = version2.size();

        int p1 = 0, p2 = 0;

        while (p1 < l1 || p2 < l2) {
            int v1 = 0, v2 = 0;

            while (p1 < l1 && version1[p1] != '.') {
                v1 *= 10;
                v1 += version1[p1++] - '0';
            }

            while (p2 < l2 && version2[p2] != '.') {
                v2 *= 10;
                v2 += version2[p2++] - '0';
            }

            if (v1 > v2) return 1;
            if (v1 < v2) return -1;

            if (p1 < l1 && version1[p1] == '.') p1++;
            if (p2 < l2 && version2[p2] == '.') p2++;
        }

        return 0;
    }
};


int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.compareVersion("10", "10.1") << endl;
    return 0;
}
