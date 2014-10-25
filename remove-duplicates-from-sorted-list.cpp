#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) {
            return head;
        }

        ListNode *pre = head;
        ListNode *t = head->next;

        while(t) {
            if (t->val == pre->val) {
                pre->next = t->next;
            } else {
                pre = t;
            }
            t = pre->next;
        }

        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    ListNode node1(1), node2(1), node3(2), node4(3), node5(3);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode *h = solve.deleteDuplicates(&node1);
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;

    return 0;
}
