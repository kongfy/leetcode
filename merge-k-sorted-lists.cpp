#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct data
{
    int val, index;
};

class Heap
{
public:
    data extractMin()
    {
        data temp;
        int n = size();
        temp = _storage[0];
        _storage[0] = _storage[n - 1];
        _storage.pop_back();

        adjustHeap(0);

        return temp;
    }

    void insert(int val, int index)
    {
        data temp;
        temp.val = val;
        temp.index = index;

        _storage.push_back(temp);

        int i = size() - 1;
        while (i != 0 && _storage[i].val < _storage[(i-1) / 2].val) {
            data temp = _storage[i];
            _storage[i] = _storage[(i-1) / 2];
            _storage[(i-1) / 2] = temp;

            i = (i-1) / 2;
        }
    }

    int size()
    {
        return _storage.size();
    }

private:
    void adjustHeap(int index)
    {
        int n = size();
        int left = index * 2 + 1;
        int right = left + 1;

        int t = index;
        if (left < n && _storage[t].val > _storage[left].val) {
            t = left;
        }

        if (right < n && _storage[t].val > _storage[right].val) {
            t = right;
        }

        if (t != index) {
            data temp = _storage[t];
            _storage[t] = _storage[index];
            _storage[index] = temp;

            adjustHeap(t);
        }
    }

    vector<data> _storage;
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode head(0);
        ListNode *tail = &head;
        int n = lists.size();
        Heap heap;

        for (int i = 0; i < n; ++i) {
            if (lists[i]) {
                heap.insert(lists[i]->val, i);
            }
        }

        while (heap.size()) {
            data temp = heap.extractMin();

            tail->next = lists[temp.index];
            tail = tail->next;

            lists[temp.index] = lists[temp.index]->next;
            tail->next = NULL;

            if (lists[temp.index]) {
                heap.insert(lists[temp.index]->val, temp.index);
            }
        }

        return head.next;
    }
};

int main(int argc, char *argv[])
{
    vector<ListNode *> lists(10);
    for (int i = 0; i < 10; ++i) {
        lists[i] = new ListNode(0);
        ListNode *tail = lists[i];

        for (int j = 0; j < 10; ++j) {
            tail->next = new ListNode((j + 1) * (i + 1));
            tail = tail->next;
        }
    }

    Solution solver;
    ListNode *head = solver.mergeKLists(lists);

    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;

    return 0;
}
