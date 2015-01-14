#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int sqrt(int x)
    {
        unsigned long long l = 0;
        unsigned long long r = x;

        while (l < r) {
            unsigned long long mid = (l + r) / 2;
            unsigned long long temp = mid * mid;

            if (temp == x) {
                return mid;
            }

            if (temp < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l * l > x ? l - 1 : l;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.sqrt(2147395599) << endl;
    cout << solver.sqrt(1473634757) << endl;
    cout << solver.sqrt(2147483647) << endl;


    return 0;
}
