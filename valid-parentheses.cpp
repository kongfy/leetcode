#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                _stack.push(c);
            } else {
                if (_stack.empty()) {
                    return false;
                }

                char top = _stack.top();

                if (c == ')' && top != '(') {
                    return false;
                } else if (c == ']' && top != '[') {
                    return false;
                } else if (c == '}' && top != '{') {
                    return false;
                }

                _stack.pop();
            }
        }

        if (_stack.empty()) {
            return true;
        }
        return false;
    }

private:
    stack<char> _stack;
};

int main(int argc, char *argv[])
{

    return 0;
}
