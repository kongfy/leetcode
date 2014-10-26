#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector <int> > result;
        vector<int> c;

        for (int i = 0; i < k; ++i) {
            c.push_back(i + 1);
        }
        result.push_back(c);

        for (int i = 0; i < count(n, k) - 1; ++i) {
            c = next(c, n, k);
            result.push_back(c);
        }

        return result;
    }
private:
    int count(int n, int k)
    {
        int ans = 1;
        int t = n - k;

        while (n > t) {
            ans *= n;
            n--;
        }

        while (k > 0) {
            ans /= k;
            k--;
        }

        return ans;
    }

    vector<int> next(vector<int> c, int n, int k)
    {
        for (int i = k - 1; i >= 0; --i) {
            int max = n - (k - i - 1);

            if (c[i] < max) {
                c[i]++;
                for (int j = i + 1; j < k; ++j) {
                    c[j] = c[j - 1] + 1;
                }

                break;
            } else {
                continue;
            }
        }
        return c;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    for (vector<int> c : solve.combine(13, 3)) {
        for (int n : c) {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}
