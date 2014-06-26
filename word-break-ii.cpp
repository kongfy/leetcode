#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        preProcess(s, dict);

        int length = s.length();
        return getSolutions(s, dict, length - 1);
    }

    Solution():_f()
    {
    }

    ~Solution()
    {
        if (_f) {
            free(_f);
            _f = NULL;
        }
    }

private:
    bool preProcess(string s, unordered_set<string> &dict)
    {
        if (s.empty()) {
            return true;
        }

        int length = s.length();

        if (_f) {
            free(_f);
            _f = NULL;
        }
        _f = (bool *)malloc(length * sizeof(bool));
        memset(_f, false, length * sizeof(bool));

        for (int i = 0; i < length; ++i) {
            string sub = s.substr(0, i + 1);
            if (dict.count(sub)) {
                _f[i] = true;
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (_f[j]) {
                    string sub = s.substr(j + 1, i - j);
                    if (dict.count(sub)) {
                        _f[i] = true;
                    }
                }
            }
        }

        return _f[length - 1];
    }

    vector<string> getSolutions(string s, unordered_set<string> &dict, int index)
    {
        vector<string> ans;

        if (!_f[index]) {
            return ans;
        }

        for (int i = 0; i < index; ++i) {
            vector<string> temp;
            if (_f[i]) {
                string sub = s.substr(i + 1, index - i);
                if (dict.count(sub)) {
                    temp = getSolutions(s, dict, i);

                    vector<string>::iterator iter;
                    for (iter = temp.begin(); iter != temp.end(); ++iter) {
                        ans.push_back(*iter + " " + sub);
                    }
                }
            }
        }

        string sub = s.substr(0, index + 1);
        if (dict.count(sub)) {
            ans.push_back(sub);
        }

        return ans;
    }

    bool *_f;
};

int main(int argc, char *argv[])
{
    string s("catsanddog");
    unordered_set<string> dict;
    dict.insert(string("cat"));
    dict.insert(string("cats"));
    dict.insert(string("cats"));
    dict.insert(string("and"));
    dict.insert(string("sand"));
    dict.insert(string("dog"));
    
    Solution solution;
    vector<string> ans = solution.wordBreak(s, dict);

    vector<string>::iterator iter;
    for (iter = ans.begin(); iter != ans.end(); ++iter) {
        cout << *iter << endl;
    }
    
    return 0;
}

