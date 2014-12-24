#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s)
    {
        string temp;

        int t = s.size() - 1;
        int r = -1;

        while (t >= 0) {
            if (s[t] != ' ') {
                if (r < 0) {
                    r = t;
                }
            }

            if (s[t] == ' ') {
                if (r > 0) {
                    // find a word between [(t+1)...r]
                    if (temp.size()) {
                        temp.append(" ");
                    }
                    temp.append(s.substr(t + 1, r - t));

                    r = -1;
                }
            }

            t--;
        }

        if (r >= 0) {
            // find a word between [0...r]
            if (temp.size()) {
                temp.append(" ");
            }
            temp.append(s.substr(0, r + 1));

            r = -1;
        }

        s = temp;
    }
};

int main(int argc, char *argv[])
{
    string s("a");
    Solution solver;

    solver.reverseWords(s);
    cout << s << endl;

    return 0;
}
