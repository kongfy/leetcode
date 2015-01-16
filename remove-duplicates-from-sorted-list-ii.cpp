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
        ListNode headnode(0);
        headnode.next = head;

        ListNode *pre = &headnode;
        ListNode *p = head;
        ListNode *q;

        while (p) {
            q = p->next;

            while (q && q->val == p->val) {
                q = q->next;
            }

            if (q != p->next) {
                pre->next = q;
            } else {
                pre = p;
            }

            p = q;
        }

        return headnode.next;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
