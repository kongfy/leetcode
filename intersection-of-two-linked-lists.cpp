#include <cstdlib>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int len_a = length(headA);
        int len_b = length(headB);

        while (len_a > len_b) {
            headA = headA->next;
            len_a--;
        }

        while (len_b > len_a) {
            headB = headB->next;
            len_b--;
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }

private:
    int length(ListNode *head)
    {
        ListNode *p = head;
        int len = 0;

        while (p) {
            len++;
            p = p->next;
        }

        return len;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
