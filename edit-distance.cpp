#include <cstdio>
#include <cstdlib>
#include <string>

using std::string;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        _len1 = word1.length();
        _len2 = word2.length();
        
        if (_storage) {
            free(_storage);
        }
        _storage = (unsigned int *)malloc(_len1 * _len2 * sizeof(unsigned int));
        memset(_storage, 0xff, _len1 * _len2 * sizeof(unsigned int));

        for (int i = 0; i < _len1; ++i) {
            for (int j = 0; j < _len2; ++j) {
                if (word1[i] == word2[j]) {
                    setF(i, j, min(getF(i, j), getF(i - 1, j - 1)));
                } else {
                    setF(i, j, min(getF(i, j), getF(i - 1, j - 1) + 1));
                }
                setF(i, j, min(getF(i, j), getF(i - 1, j) + 1));
                setF(i, j, min(getF(i, j), getF(i, j - 1) + 1));
            }
        }

        return getF(_len1 - 1, _len2 - 1);
    }

    ~Solution()
    {
        if (_storage) {
            free(_storage);
        }
    }

private:
    unsigned int *_storage;
    int _len1, _len2;
    
    inline unsigned int getF(int i, int j)
    {
        if (i < 0 & j < 0) return 0;
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        return _storage[i * _len2 + j];
    }

    inline void setF(int i, int j, unsigned int value)
    {
        _storage[i * _len2 + j] = value;
    }

    inline unsigned int min(unsigned int a, unsigned int b)
    {
        if (a < b) {
            return a;
        }
        return b;
    }
};

int main(int argc, char *argv[])
{
    string a("");
    string b("a");

    Solution solution;
    printf("%d\n", solution.minDistance(a, b));
    
    return 0;
}

