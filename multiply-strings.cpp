#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        string res = "0";

        int n = num1.size();
        for (int i = n - 1; i >= 0; --i) {
            int z = n - 1 - i;

            string temp = multiplyInt(num2, num1[i] - '0');
            if (!isZero(temp)) {
                for (int j = 0; j < z; ++j) temp = temp + '0';
            } else {
                temp = "0";
            }
            res = add(res, temp);
        }

        return res;
    }

    bool isZero(string num)
    {
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            if (num[i] != '0') {
                return false;
            }
        }
        return true;
    }

    string multiplyInt(string num, int a)
    {
        string res = "";
        int t = 0;

        int n = num.size();
        for (int i = n - 1; i >= 0; --i) {
            int temp = (num[i] - '0') * a + t;
            t = temp / 10;
            temp %= 10;
            res = (char)(temp + '0') + res;
        }

        while (t) {
            res = (char)(t % 10 + '0') + res;
            t /= 10;
        }

        return res;
    }

    string add(string num1, string num2)
    {
        string res;
        int l1 = num1.size();
        int l2 = num2.size();

        int i = l1 - 1;
        int j = l2 - 1;
        int t = 0;
        while (i >= 0 || j >= 0) {
            int temp = t;

            if (i >= 0) {
                temp += num1[i] - '0';
            }

            if (j >= 0) {
                temp += num2[j] - '0';
            }

            res = (char)(temp % 10 + '0') + res;
            t = temp / 10;
            i--; j--;
        }

        while (t) {
            res = (char)(t % 10 + '0') + res;
            t /= 10;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.multiply("123", "456") << endl;

    return 0;
}
