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
        
        int length = 0;
        ListNode *p = head;
        while (p) {
            length++;
            p = p->next;
        }
        
        return mergesort(head, length);
    }

private:
    ListNode *mergesort(ListNode *head, int length)
    {
        if (!head) {
            return NULL;
        }

        if (length == 1) {
            return head;
        }
        
        int mid_index = length / 2;

        ListNode *left, *right;
        ListNode *mid = head, *pre = NULL;
        for (int i = 0; i < mid_index; ++i) {
            pre = mid;
            mid = mid->next;
        }

        if (pre) {
            pre->next = NULL;
            left = head;
        } else {
            left = NULL;
        }

        right = mid;
        
        left = mergesort(left, mid_index);
        right = mergesort(right, length - mid_index);

        return merge(left, right);
    }
    
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        if (!h1) {
            return h2;
        }

        if (!h2) {
            return h1;
        }

        ListNode *head, *tail;
        head = tail = NULL;

        while (h1 && h2) {
            ListNode *temp;
            
            if (h1->val < h2->val) {
                temp = h1;
                h1 = h1->next;
            } else {
                temp = h2;
                h2 = h2->next;
            }

            if (!head) {
                head = temp;
            } else {
                tail->next = temp;
            }
            tail = temp;
            temp->next = NULL;

        }

        if (h1) {
            tail->next = h1;
        } else if (h2) {
            tail->next = h2;
        }

        return head;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1), node2(2), node3(3), node4(4), node5(5);

    ListNode *head = &node5;
    node5.next = &node4;
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

