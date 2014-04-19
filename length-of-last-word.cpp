#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <ctype.h>

class Solution {
public:
    int lengthOfLastWord(const char *s)
    {
        int length = strlen(s);
        int count = 0;
        int index =  length - 1;

        while (index >= 0) {
            if (isalpha(s[index])) {
                count++;
            } else {
                if (count != 0) {
                    break;
                }
                
            }
            
            index--;
        }

        return count;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    
    printf("%d\n", solution.lengthOfLastWord("Hello World"));
    return 0;
}

