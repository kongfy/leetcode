#include <stack>
#include <iostream>

using namespace std;

class MinStack
{
public:
    void push(int x)
    {
        _stack.push(x);

        if (_minStack.empty() || x <= _minStack.top()) {
            _minStack.push(x);
        }
    }

    void pop()
    {
        if (_stack.empty()) {
            return; // illegal
        }

        int top = _stack.top();
        _stack.pop();

        if (top == _minStack.top()) {
            _minStack.pop();
        }
    }

    int top()
    {
        if (_stack.empty()) {
            return 0; // illegal
        }

        return _stack.top();
    }

    int getMin()
    {
        if (_stack.empty()) {
            return 0; // illegal
        }

        return _minStack.top();
    }

private:
    stack<int> _stack;
    stack<int> _minStack;
};

int main(int argc, char *argv[])
{
    MinStack stack;

    cout << stack.top() << endl;
    cout << stack.getMin() << endl;
    return 0;
}
