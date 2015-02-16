#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string res;

        long long left = (long long)numerator / denominator;
        long long t = (long long)numerator % denominator;
        long long d = denominator;

        res = to_string(left);
        if (!t) {
            return res;
        } else {
            res = res + '.';
            if (left == 0 && ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))) {
                res = '-' + res;
            }
        }

        t = abs(t);
        d = abs(d);

        int temp = res.size();
        unordered_map<long long, int> record;

        int i = 0;
        while (t) {
            t *= 10;
            if (record.find(t) != record.end()) {
                int index = record[t] + temp;
                res = res.substr(0, index) + '(' + res.substr(index) + ')';
                return res;
            } else {
                record[t] = i;
                res = res + (char)(t / d + '0');
                t %= d;
            }

            i++;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
