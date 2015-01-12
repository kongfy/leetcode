#include <vector>
#include <cstdio>
#include <iostream>

using namespace::std;

typedef enum {
    Left = 0,
    Right
} Mode;
    
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        int left = subSearch(A, n, target, Left);
        int right = subSearch(A, n, target, Right);

        return {left, right};
    }

private:
    int subSearch(int A[], int n, int target, Mode mode) {
        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (Left == mode) {
                int mid = (l + r) / 2;
                if (A[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            
            if (Right ==  mode) {
                int mid = (l + r + 1) / 2;
                if (A[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
        }
        
        return A[l] == target ? l : -1;
    }
};


int main(int argc, char *argv[])
{
    int A[6] = {5, 7, 7, 8, 8, 10};

    Solution solution = Solution();
    vector<int> result = solution.searchRange(A, 6, 8);

    for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;

    
    return 0;
}
