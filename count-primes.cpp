#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n)
    {
        int count = 0;
        bool *check = new bool[n];
        memset(check, 0, n * sizeof(bool));

        for (int i = 2; i < n; ++i) {
            if (i == 2 || i == 3 || i == 5 || i == 7) count++;
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) continue;
            if (!check[i]) {
                count++;

                int temp = i;
                while (temp < n) {
                    check[temp] = true;
                    temp += i;
                }
            }
        }

        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.countPrimes(100) << endl;

    return 0;
}
