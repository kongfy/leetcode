#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(int A[], int n)
    {
        int far = 0;
        int index = 0;

        while (index < n && index <= far) {
            far = max(far, index + A[index]);
            if (far >= n - 1) return true;
            index++;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
