#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        string t("");

        while (--n > -1) {
            int a = n % 26;
            char c;
            c = 'A' + a;
            n /= 26;
            t = c + t;
        }

        return t;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    for (int i = 1; i < 100; ++i) {
        cout << solver.convertToTitle(i) << endl;
    }
    return 0;
}
