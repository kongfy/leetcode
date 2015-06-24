#include <queue>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        _storage.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = _storage.size();
        for (int i = 0; i < n - 1; ++i) {
            int t = _storage.front();
            _storage.pop();
            _storage.push(t);
        }

        _storage.pop();
    }

    // Get the top element.
    int top() {
        return _storage.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return _storage.empty();
    }

private:
    queue<int> _storage;
};
