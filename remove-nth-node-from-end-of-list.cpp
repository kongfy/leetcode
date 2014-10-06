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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p1, *p2;
        p1 = p2 = head;
        for (int i = 0; i < n; ++i) {
            p1 = p1->next;
        }

        if (!p1) {
            head = head->next;
        } else {
            while (p1->next) {
                p1 = p1->next;
                p2 = p2->next;
            }

            p2->next = p2->next->next;
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

    ListNode *result = solve.removeNthFromEnd(&node1, 2);
    ListNode *p = result;
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;

    return 0;
}
