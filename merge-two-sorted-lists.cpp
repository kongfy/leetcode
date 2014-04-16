/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        ListNode *h1 = l1, *h2 = l2;
        ListNode *head = NULL, *tail = NULL, *temp = NULL;

        while (h1 || h2) {
            if (h1 && h2) {
                if (h1->val <= h2->val) {
                    temp = h1;
                    h1 = h1->next;
                } else {
                    temp = h2;
                    h2 = h2->next;
                }
            } else {
                if (h1) {
                    temp = h1;
                    h1 = h1->next;
                }
                if (h2) {
                    temp = h2;
                    h2 = h2->next;
                }
            }

            if (!head) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }
        
        return head;
    }
};
