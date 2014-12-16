#include <iostream>
#include <vector>

using namespace std;

struct RomanChar
{
    int num;
    char c;
};

class Solution {
public:
    Solution() {
        RomanChar roman;

        roman.num = 1000;
        roman.c = 'M';
        this->_roman_list.push_back(roman);

        roman.num = 500;
        roman.c = 'D';
        this->_roman_list.push_back(roman);

        roman.num = 100;
        roman.c = 'C';
        this->_roman_list.push_back(roman);

        roman.num = 50;
        roman.c = 'L';
        this->_roman_list.push_back(roman);

        roman.num = 10;
        roman.c = 'X';
        this->_roman_list.push_back(roman);

        roman.num = 5;
        roman.c = 'V';
        this->_roman_list.push_back(roman);

        roman.num = 1;
        roman.c = 'I';
        this->_roman_list.push_back(roman);
    }

    string intToRoman(int num) {
        string ans;

        int temp = 1;
        while (num) {
            string roman_d;
            int d = num % 10;
            d *= temp;
            num /= 10;
            temp *= 10;

            if (d == 0) {
                continue;
            }

            int i = 0;
            for (i = 0; i < this->_roman_list.size(); ++i) {
                if (this->_roman_list[i].num <= d) {
                    break;
                }
            }

            if (2 == i || 4 == i || 6 == i || 0 == i) {
                // C || X || I

                int t = d / this->_roman_list[i].num;
                if (4 == t) {
                    roman_d.push_back(this->_roman_list[i].c);
                    roman_d.push_back(this->_roman_list[i - 1].c);
                } else {
                    while (t > 0) {
                        roman_d.push_back(this->_roman_list[i].c);
                        t--;
                    }
                }
            } else {
                int t = (d - this->_roman_list[i].num) / this->_roman_list[i + 1].num;
                if (4 == t) {
                    roman_d.push_back(this->_roman_list[i + 1].c);
                    roman_d.push_back(this->_roman_list[i - 1].c);
                } else {
                    roman_d.push_back(this->_roman_list[i].c);
                    while (t > 0) {
                        roman_d.push_back(this->_roman_list[i + 1].c);
                        t--;
                    }
                }
            }

            ans = roman_d + ans;
        }

        return ans;
    }

private:
    vector <struct RomanChar> _roman_list;
};

int main(int argc, char *argv[])
{
    Solution solver;

    cout << solver.intToRoman(1) << endl;
    return 0;
}
