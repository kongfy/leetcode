#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int atoi(string str)
    {
        int l = 0;
        while (str[l] == ' ') l ++;

        int flag = 1;
        if (str[l] == '+') l++;
        else if (str[l] == '-') {
            flag = -1;
            l++;
        }

        int value = 0;
        while (str[l] >= '0' && str[l] <= '9') {
            int digit = str[l++] - '0';
            if (value > INT_MAX / 10 || (value == INT_MAX / 10 && digit >= 8)) {
                return flag == 1 ? INT_MAX : INT_MIN;
            }

            value *= 10;
            value += digit;
        }

        return flag * value;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    char *str = "123";

    cout << atoi(str) << endl;
    cout << solve.atoi(str) << endl;
    return 0;
}
