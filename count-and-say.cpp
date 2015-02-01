#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 0) {
            return "";
        }

        string str("1");


        for (int i = 1; i < n; ++i) {
            string t;
            int j = 0;

            while (j < str.size()) {
                int cnt = 1;
                while (j + 1 < str.size() && str[j] == str[j + 1]) {
                    j++;
                    cnt++;
                }

                t += to_string(cnt);
                t += str[j];

                j++;
            }
            str = t;
        }

        return str;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;


    cout << solver.countAndSay(30) << endl;

    return 0;
}
