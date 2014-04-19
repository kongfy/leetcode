/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head) {
            return NULL;
        }
        
        RandomListNode *p = head, *q = NULL;
        while (p) {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }

        p = head;
        q = NULL;
        while (p) {
            q = p->next;
            if (p->random) {
                q->random = p->random->next;
            }
            p = q->next;
        }

        p = head;
        q = NULL;
        RandomListNode *new_head = NULL, *tail = NULL;
        while (p) {
            q = p->next;
            p->next = q->next;
            
            q->next = NULL;
            if (!new_head) {
                new_head = q;
            } else {
                tail->next = q;
            }
            tail = q;
            
            p = p->next;
        }
        
        return new_head;
    }
};
