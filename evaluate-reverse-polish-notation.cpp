#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        for (int i = 0; i < tokens.size(); ++i) {
            string &token = tokens[i];
            if (token == "+") {
                int op2 = _stack.top();
                _stack.pop();
                int op1 = _stack.top();
                _stack.pop();

                int op = op1 + op2;
                _stack.push(op);
            } else if (token == "-") {
                int op2 = _stack.top();
                _stack.pop();
                int op1 = _stack.top();
                _stack.pop();

                int op = op1 - op2;
                _stack.push(op);
            } else if (token == "*") {
                int op2 = _stack.top();
                _stack.pop();
                int op1 = _stack.top();
                _stack.pop();

                int op = op1 * op2;
                _stack.push(op);
            } else if (token == "/") {
                int op2 = _stack.top();
                _stack.pop();
                int op1 = _stack.top();
                _stack.pop();

                int op = op1 / op2;
                _stack.push(op);
            } else {
                int op = stoi(token);
                _stack.push(op);
            }
        }

        if (_stack.empty()) {
            return 0;
        }
        return _stack.top();
    }

private:
    stack<int> _stack;
};

int main(int argc, char *argv[])
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};

    Solution solver;
    cout << solver.evalRPN(tokens) << endl;

    return 0;
}
