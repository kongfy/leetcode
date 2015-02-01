#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0) {
            return "";
        }

        int len = 0;
        while (true) {
            char c;
            bool flag = false;
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].size() < len + 1) {
                    flag = true;
                    break;
                }
                if (i == 0) {
                    c = strs[i][len];
                } else {
                    if (strs[i][len] != c) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
            len ++;
        }

        return strs[0].substr(0, len);
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
