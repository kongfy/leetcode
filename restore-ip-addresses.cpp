#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static inline
int min(int a, int b)
{
    if (a < b) {
        return a;
    }
    return b;
}

class Solution
{
    bool validateIpNumberString(string str)
    {
        int num = atoi(str.c_str());

        if (str.length() > 3 || str.length() == 0) {
            return false;
        }

        if (str.length() > 1 && str.substr(0, 1) == "0") {
            return false;
        }

        if (num >= 0 && num <= 255) {
            return true;
        }
        return false;
    }

    vector<string> subIpAddress(string s, int fragment)
    {
        vector<string> ans;

        if (!fragment || s.length() < fragment) {
            return ans;
        }

        for (int i = 1; i <= min(3, s.length()); ++i) {
            string prefix = s.substr(0, i);

            if (!validateIpNumberString(prefix)) {
                continue;
            }

            if (fragment == 1 && i == s.length()) {
                ans.push_back(prefix);
            } else {
                vector<string> subIps = subIpAddress(s.substr(i), fragment - 1);

                for (vector<string>::iterator iter = subIps.begin(); iter != subIps.end(); iter++) {
                    ans.push_back(prefix + '.' + *iter);
                };
            }
        }

        return ans;
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        return subIpAddress(s, 4);
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    string ipstr = string("010010");

    vector<string> ips = solve.restoreIpAddresses(ipstr);

    for (vector<string>::iterator iter = ips.begin(); iter != ips.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
