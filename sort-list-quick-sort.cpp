#include <cstdio>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head) {
            return NULL;
        }
        
        ListNode *mid = head;
        ListNode *t = head->next;

        ListNode *left, *right;
        left = right = NULL;
        while (t) {
            ListNode *temp = t->next;
            if (t->val < mid->val) {
                t->next = left;
                left = t;
            } else {
                t->next = right;
                right = t;
            }
            
            t = temp;
        }

        left = sortList(left);
        right = sortList(right);

        if (!left) {
            left = mid;
        } else {
            ListNode *left_tail = left;
            while (left_tail->next) {
                left_tail = left_tail->next;
            }

            left_tail->next = mid;
        }
        mid->next = right;
        return left;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1), node2(2), node3(3), node4(4);

    ListNode *head = &node4;
    node4.next = &node3;
    node3.next = &node2;
    node2.next = &node1;

    Solution solution;
    head = solution.sortList(head);

    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return 0;
}

