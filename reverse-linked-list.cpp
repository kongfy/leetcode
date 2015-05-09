struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode fake(0);

        ListNode *p = head;
        while (p) {
            ListNode *t = p->next;

            p->next = fake.next;
            fake.next = p;

            p = t;
        }

        return fake.next;
    }
};
