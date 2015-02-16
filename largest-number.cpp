#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool cmp(const int &a, const int &b)
{
    string str_a = to_string(a) + to_string(b);
    string str_b = to_string(b) + to_string(a);
    return str_a < str_b;
}

class Solution
{
public:
    string largestNumber(vector<int> &num)
    {
        sort(num.begin(), num.end(), cmp);

        if (num[num.size() - 1] == 0) return "0";

        string res;
        for (int i = num.size() - 1; i >= 0; --i) {
            res = res + to_string(num[i]);
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> num = {3, 30, 34, 5, 9};
    Solution solver;
    string str = solver.largestNumber(num);

    cout << str << endl;

    return 0;
}
