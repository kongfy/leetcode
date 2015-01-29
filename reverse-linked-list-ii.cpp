struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode fake(0);
        fake.next = head;

        ListNode *pre = &fake;
        ListNode *t_pre = &fake;
        ListNode *t_start = fake.next;
        ListNode *p = fake.next, *q;

        int pos = 1;
        while (p && pos <= n) {
            q = p->next;

            if (pos == m) {
                t_pre = pre;
                t_start = p;
            }

            if (pos == n) {
                t_pre->next = p;
                t_start->next = q;
            }

            if (pos > m && pos <= n) {
                p->next = pre;
            }

            pos++;
            pre = p;
            p = q;
        }

        return fake.next;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
