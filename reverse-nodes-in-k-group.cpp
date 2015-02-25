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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k <= 1) {
            return head;
        }

        ListNode fake(0);
        fake.next = head;

        head = &fake;

        while (head) {
            ListNode *tail = head;
            int t = k;
            while (t) {
                tail = tail->next;
                if (!tail) {
                    break;
                }
                t--;
            }

            if (t) {
                break;
            }

            // swap in group
            ListNode *p, *q, *temp, *last;
            last = tail->next;
            temp = head->next;
            p = head;

            while (temp != last) {
                q = temp->next;
                temp->next = p;

                p = temp;
                temp = q;
            }

            temp = head->next;
            temp->next = last;
            head->next = tail;

            head = temp;
        }

        return fake.next;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1), node2(2), node3(3), node4(4), node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    Solution solver;

    ListNode *p = solver.reverseKGroup(&node1, 3);

    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;

    return 0;
}
