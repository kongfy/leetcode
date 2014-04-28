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
    void reorderList(ListNode *head)
    {
        if (!head) {
            return;
        }
        
        int length = listLength(head);
        int half = length / 2;

        ListNode *break_point = nodeAtIndex(head, half);
        ListNode *post = break_point->next;
        break_point->next = NULL;

        post = reverseList(post);
        
        merge(head, post);
    }

private:
    int listLength(ListNode *head)
    {
        int length = 0;
        ListNode *p = head;
        
        while (p) {
            length++;
            p = p->next;
        }
        
        return length;
    }

    ListNode *nodeAtIndex(ListNode *head, int index)
    {
        ListNode *p = head;
        while (index > 0 && p->next) {
            p = p->next;
            index--;
        }
        return p;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head) {
            return NULL;
        }
        
        ListNode *pre = NULL;
        ListNode *next = NULL;
        ListNode *p = head;

        while (p) {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }

        return pre;
    }

    void merge(ListNode *h1, ListNode *h2)
    {
        ListNode *p1 = h1;
        ListNode *p2 = h2;
        while (p1 && p2) {
            ListNode *t1 = p1->next;
            ListNode *t2 = p2->next;
                
            p1->next = p2;
            p2->next = t1;

            if (!t1) {
                p2->next = t2;
            }

            p1 = t1;
            p2 = t2;
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode *head = &node1;

    Solution solution;
    solution.reorderList(head);

    ListNode *p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    
    return 0;
}
