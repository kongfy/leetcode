#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        int n = words.size();
        int l, r, len;

        vector<string> lines;
        l = 0;

        while (l < n) {
            r = l;
            len = 0;
            while (len < L && r < n) {
                int space = r - l;
                if (len + space + words[r].size() <= L) {
                    len += words[r].size();
                    r++;
                } else {
                    break;
                }
            }
            r--;

            string line;
            if (r >= n-1) {
                int t = 0;
                while (l <= r) {
                    line += words[l];
                    t += words[l].size();
                    if (t < L) {
                        line += ' ';
                        t++;
                    }
                    l++;
                }
                while (t < L) {
                    line += ' ';
                    t++;
                }
            } else {
                if (r - l > 0) {
                    int space = L - len;
                    int inter = space / (r-l);
                    int extra = space % (r-l);

                    while (l <= r) {
                        line += words[l];
                        if (l == r) break;
                        if (extra) {
                            line += ' ';
                            extra--;
                        }
                        for (int i = 0; i < inter; ++i) {
                            line += ' ';
                        }
                        l++;
                    }
                } else if (r - l == 0) {
                    int t = 0;
                    line += words[l];
                    t += words[l].size();
                    while (t < L) {
                        line += ' ';
                        t++;
                    }
                } else {
                    line += words[l];
                    r++;
                }
            }

            lines.push_back(line);
            l = r + 1;
        }

        return lines;
    }
};

int main(int argc, char *argv[])
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> lines;
    Solution solver;
    lines = solver.fullJustify(words, 16);

    for (string & line : lines) {
        cout << line << endl;
    }

    return 0;
}
