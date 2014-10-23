#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head) {
            return NULL;
        }

        ListNode slist(0), elist(0), llist(0);
        ListNode *p, *q;
        p = head;

        while (p) {
            q = p->next;

            if (p->val < x) {
                p->next = slist.next;
                slist.next = p;
            } else {
                p->next = llist.next;
                llist.next = p;
            }

            p = q;
        }

        ListNode list(0);
        ListNode *t;

        while (llist.next) {
            t = llist.next;
            llist.next = t->next;
            t->next = list.next;
            list.next = t;
        }

        while (slist.next) {
            t = slist.next;
            slist.next = t->next;
            t->next = list.next;
            list.next = t;
        }

        return list.next;
    }
};


int main(int argc, char *argv[])
{
    ListNode node1(1), node2(4), node3(3), node4(2), node5(5), node6(2);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    Solution solve;
    ListNode *result = solve.partition(&node1, 3);
    ListNode *p = result;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
