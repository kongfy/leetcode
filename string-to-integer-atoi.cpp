#include <iostream>
#include <cstdlib>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution
{
public:
    int atoi(const char *str)
    {
        long long int absi = 0;
        char c;

        while (c = *str) {
            if (' ' == c) {
                str++;
            } else {
                break;
            }
        }

        int flag = 1;
        c = *str;
        if ('+' == c) {
            flag = 1;
            str++;
        } else if ('-' == c) {
            flag = -1;
            str++;
        }

        while (c = *str++) {
            if (c >= '0' && c <= '9') {
                absi *= 10;
                absi += c - '0';

                if (flag * absi > INT_MAX) {
                    return INT_MAX;
                }
                if (flag * absi < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                break;
            }
        }
        return flag * absi;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    char *str = "2147483648";

    cout << atoi(str) << endl;
    cout << solve.atoi(str) << endl;
    return 0;
}
