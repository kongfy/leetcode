#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        string simple;

        int n = path.size();
        int l = 0;
        int i = l;
        while (l < n) {
            while (l < n && path[l] == '/') l++;
            i = l;
            while (i < n && path[i] != '/') i++;

            int r = i - 1;
            if (l == r && path[l] == '.') {
                l = i + 1;
                continue;
            }

            if (l == r - 1 && path[l] == '.' && path[r] == '.') {
                int t = simple.size() - 1;
                while (t > 0 && simple[t] != '/') t--;
                simple = simple.substr(0, t);
                l = i + 1;
                continue;
            }

            if (l <= r) {
                simple = simple + '/';
                simple = simple + path.substr(l, r + 1 - l);
            }

            l = i + 1;
        }

        if (simple.size() == 0) simple = "/";

        return simple;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    cout << solver.simplifyPath("/..////") << endl;
    return 0;
}
