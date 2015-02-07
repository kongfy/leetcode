#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        int len = s.size();
        if (len == 0) return;

        reverseSub(s, 0, len - 1);

        int l = 0;
        int r = l;
        while (l < len) {
            r = l;
            while (r < len && s[r] != ' ') r++;
            reverseSub(s, l, r - 1);
            l = r + 1;
        }
    }

private:
    void reverseSub(string &s, int l, int r)
    {
        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    string str("the sky is blue");
    solver.reverseWords(str);

    cout << str << endl;

    return 0;
}
