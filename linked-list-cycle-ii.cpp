struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head) {
            return false;
        }

        ListNode *fast = head, *slow = head;

        while (slow->next && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode *p = head, *q = slow;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }

        return NULL;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
