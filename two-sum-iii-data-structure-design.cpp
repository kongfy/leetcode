#include <unordered_map>
#include <iostream>

using namespace std;

class TwoSum
{
public:
    void add(int number)
    {
        if (_storage.find(number) != _storage.end()) {
            _storage[number] = _storage[number] + 1;
        } else {
            _storage[number] = 1;
        }
    }

    bool find(int value)
    {
        for (auto pair : _storage) {
            if (2 * pair.first == value) {
                if (pair.second > 1) {
                    return true;
                } else {
                    continue;
                }
            }

            if (_storage.find(value - pair.first) != _storage.end()) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int, int> _storage;
};

int main(int argc, char *argv[])
{
    TwoSum solver;

    solver.add(1);
    solver.add(3);
    solver.add(5);

    cout << solver.find(4) << endl;
    cout << solver.find(7) << endl;

    return 0;
}
