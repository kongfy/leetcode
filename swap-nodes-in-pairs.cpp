#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **pre = &head;
        ListNode *p, *q;

        p = head;
        while (p) {
            q = p->next;
            if (!q) break;

            *pre = q;
            p->next = q->next;
            q->next = p;

            pre = &p->next;
            p = p->next;
        }

        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode *p = solve.swapPairs(&node1);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
