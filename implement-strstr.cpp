#include <cstring>
#include <cstdlib>
#include <cstdio>

class Solution
{
public:
    char *strStr(char *haystack, char *needle)
    {
        if (!strlen(needle)) {
            return haystack;
        }
        return kmp(haystack, needle);
    }

private:
    void getnext(int *next, char *b)
    {
        int i, j;
        next[0] = 0;
        i = 1;
        j = 0;
        for(; b[i]; i++) {
            while (j > 0 && b[i] != b[j]) {
                j = next[j-1];
            }
            if (b[i] == b[j]) {
                j++;
            }
            next[i]=j;
        }
    }

    char *kmp(char *a, char*b)
    {
        int i, j;
        int *next;

        i = j = 0;

        int lenb = strlen(b);
        next = (int *)malloc(lenb * sizeof(int));
        memset(next, 0, lenb * sizeof(int));

        getnext(next, b);
        
        for(; a[i]; i++) {
            while (j > 0 && a[i]!= b[j]) {
                j = next[j-1];
            }
            if (a[i] == b[j]) {
                j++;
                if (!b[j]) {
                    return &a[i + 1 - lenb];
                }
            }
        }
        return NULL;
    }
};

char haystack[] = "hello, world";
char needle[] = "w";

int main(int argc, char *argv[])
{
    Solution solution;
    char *ans = solution.strStr(haystack, needle);

    printf("%s\n", ans);
    
    return 0;
}

