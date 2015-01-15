struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head) {
            return NULL;
        }

        ListNode *old_tail = head;
        ListNode *new_tail = head;
        ListNode *new_head = head;


        int len = 1;
        while (old_tail->next) {
            old_tail = old_tail->next;
            len ++;
        }

        k %= len;
        k = len - k;
        while (k > 0 && new_head) {
            new_tail = new_head;
            new_head = new_head->next;
            k--;
        }

        if (new_head && new_head != head) {
            new_tail->next = NULL;
            old_tail->next = head;
        }

        return new_head ? new_head : head;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
