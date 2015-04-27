#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> check;
        check.insert(n);

        while (n != 1) {
            int temp = 0;

            while (n != 0) {
                int t = n % 10;
                temp += t * t;
                n /= 10;
            }

            if (check.find(temp) != check.end()) {
                return false;
            } else {
                n = temp;
                check.insert(n);
            }
        }

        return true;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
