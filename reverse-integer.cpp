#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = 0;

        while (x) {
            temp *= 10;
            temp += x % 10;
            x /= 10;
        }
        return temp;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    cout << solution.reverse(12300) << endl;
    return 0;
}
