#include <cstdio>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = NULL;
        ListNode *p1 = l1, *p2 = l2;
        ListNode **p = &result;

        int tmp = 0; // 进位
        while (p1 || p2 || tmp) {
            int v1 = p1 ? p1->val : 0;
            int v2 = p2 ? p2->val : 0;

            int sum = v1 + v2 + tmp;
            tmp = sum / 10;

            *p = (ListNode *)malloc(sizeof(struct ListNode));
            (*p)->val = sum % 10;
            (*p)->next = NULL;
            p = &((*p)->next);

            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    ListNode d1n0(2), d1n1(4), d1n2(3);
    ListNode d2n0(5), d2n1(6), d2n2(4);

    d1n0.next = &d1n1;
    d1n1.next = &d1n2;
    d2n0.next = &d2n1;
    d2n1.next = &d2n2;

    Solution solution;
    ListNode *result = solution.addTwoNumbers(&d1n0, &d2n0);

    ListNode *p = result;
    while (p) {
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
