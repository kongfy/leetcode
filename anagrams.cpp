#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> result;
        unordered_map<string, vector<int> > map;

        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];

            sort(key.begin(), key.end());
            map[key].push_back(i);
        }

        for (auto it = map.begin(); it != map.end(); it ++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); ++i) {
                    result.push_back(strs[it->second[i]]);
                }
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
