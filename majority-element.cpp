#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num)
    {
        int majority = *num.begin();
        int count = 1;

        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == majority) {
                count++;
            } else {
                if (--count < 0) {
                    majority = num[i];
                    count = 1;
                }
            }
        }

        return majority;
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    vector<int> num = {1,3,2,2,2,2,1,5};

    cout << solver.majorityElement(num) << endl;

    return 0;
}
