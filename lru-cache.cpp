#include <unordered_map>

using namespace std;

struct DListNode
{
    int key, val;
    DListNode *pre, *next;
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        head.next = &head;
        head.pre = &head;
        head.key = 0;
        head.val = 0;
        _capacity = capacity;
        _num = 0;
    }

    int get(int key)
    {
        if (hash.find(key) != hash.end()) {
            DListNode *p = hash[key];
            p->pre->next = p->next;
            p->next->pre = p->pre;

            p->next = head.next;
            p->pre = &head;
            head.next->pre = p;
            head.next = p;

            return p->val;
        }
        return -1;
    }

    void set(int key, int value)
    {
        if (hash.find(key) != hash.end()) {
            DListNode *p = hash[key];
            p->pre->next = p->next;
            p->next->pre = p->pre;

            p->next = head.next;
            p->pre = &head;
            head.next->pre = p;
            head.next = p;

            p->val = value;
        } else {
            DListNode *p = new DListNode;
            p->key = key;
            p->val = value;

            if (_num == _capacity) {
                DListNode *q = head.pre;

                hash.erase(q->key);
                q->pre->next = q->next;
                q->next->pre = q->pre;

                delete q;
                _num--;
            }

            _num++;
            p->next = head.next;
            p->pre = &head;
            head.next->pre = p;
            head.next = p;
            hash[key] = p;
        }
    }

private:
    unordered_map<int, DListNode*> hash;
    DListNode head;
    int _capacity, _num;
};

int main(int argc, char *argv[])
{

    return 0;
}
