#include <iostream>
#include <string>
#include <map>


using namespace std;

class Solution {

public:
    Solution() {
        this->_roman_map['I'] = 1;
        this->_roman_map['V'] = 5;
        this->_roman_map['X'] = 10;
        this->_roman_map['L'] = 50;
        this->_roman_map['C'] = 100;
        this->_roman_map['D'] = 500;
        this->_roman_map['M'] = 1000;
    }

    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            ans += this->_roman_map[c];
            if (i > 0) {
                char b = s[i - 1];

                if (('I' == b || 'X' == b || 'C' == b) && (this->_roman_map[b] < this->_roman_map[c])) {
                    ans -= 2 * this->_roman_map[b];
                }
            }
        }

        return ans;
    }

private:
    map<char, int> _roman_map;

};

int main(int argc, char *argv[])
{
    Solution solver;

    string roman("MCDXXXVII");
    cout << solver.romanToInt(roman) << endl;
    return 0;
}
