#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        int num = 1;
        for (int i = 0; i < n; ++i) {
            num *= 2;
        }

        vector<int> gray;
        for (int i = 0; i < num; ++i) {
            gray.push_back((i >> 1) ^ i);
        }

        return gray;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;
    vector<int> gray;

    gray = solver.grayCode(3);
    for (int i = 0; i < gray.size(); ++i) {
        cout << gray[i] << endl;
    }

    return 0;
}
