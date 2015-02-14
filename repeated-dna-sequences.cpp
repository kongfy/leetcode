#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;

        int n = s.size();
        if (n <= 10) {
            return res;
        }

        int temp = 0;
        for (int i = 0; i < n; ++i) {
            temp <<= 2;
            temp |= numForDNA(s[i]);
            temp &= 0x000fffff;
            if (i >= 9) {
                if (_map.find(temp) != _map.end()) {
                    // find
                    if (_check.find(temp) == _check.end()) {
                        _check.insert(temp);
                        res.push_back(DNAForNum(temp));
                    }
                } else {
                    _map.insert(temp);
                }
            }
        }

        return res;
    }

private:
    unordered_set<int> _map, _check;

    int numForDNA(char c)
    {
        switch (c) {
        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
        }
        return 0;
    }

    char charForNum(int num)
    {
        switch (num) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        }
        return 0;
    }

    string DNAForNum(int n)
    {
        string str;
        for (int i = 0; i < 10; ++i) {
            str = charForNum(n & 3) + str;
            n >>= 2;
        }
        return str;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    for (string &str : solver.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")) {
        cout << str << endl;
    }

    return 0;
}
