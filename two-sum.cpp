#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map <int, int> map;

        for (int i = 0; i < numbers.size(); ++i) {
            if (map.find(target - numbers[i]) != map.end()) {
                return {map[target - numbers[i]] + 1, i + 1};
            }
            map[numbers[i]] = i;
        }

        return {0, 0};
    }
};

int main(int argc, char *argv[])
{
    vector<int> list = {3, 2, 4};

    Solution solver;

    for (int index : solver.twoSum(list, 6)) {
        cout << index << endl;
    }

    return 0;
}
