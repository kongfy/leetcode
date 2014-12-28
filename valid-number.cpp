#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s)
    {
        int start = 0;
        while (s[start] == ' ') {
            start ++;
        }

        int end = strlen(s);
        end--; // skip '\0'
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        if (!(start <= end)) {
            // empty string
            return false;
        }

        int i = start;
        bool flag = false;

        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9') {
            flag = true;
            i++;
        }

        if (s[i] == '.') {
            i++;

            while (s[i] >= '0' && s[i] <= '9') {
                flag = true;
                i++;
            }
        }

        if (flag && s[i] == 'e') {
            i++;

            flag = false;
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }

            while (s[i] >= '0' && s[i] <= '9') {
                i++;
                flag = true;
            }
        }

        if (flag && i > end) {
            return true;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.isNumber("0") << endl;
    cout << solver.isNumber(" 0.1 ") << endl;
    cout << solver.isNumber("abc") << endl;
    cout << solver.isNumber("1 1") << endl;
    cout << solver.isNumber("2e10") << endl;

    return 0;
}
