#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode fake(0);
        fake.next = head;

        ListNode *pre = &fake;
        ListNode *p = head;

        while (p) {
            ListNode *next = p->next;

            if (p->val == val) {
                pre->next = next;
            } else {
                pre = p;
            }

            p = next;
        }

        return fake.next;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
