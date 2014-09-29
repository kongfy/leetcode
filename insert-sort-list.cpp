#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *p = head;
        ListNode *sorted = NULL;
        while (p) {
            ListNode *node = p;
            p = p->next;

            if (!sorted) {
                sorted = node;
                sorted->next = NULL;
            } else {
                ListNode *pre = sorted;
                ListNode *post = pre->next;

                if (node->val < pre->val) {
                    sorted = node;
                    node->next = pre;
                } else {
                    while (true) {
                        if (!post) {
                            pre->next = node;
                            node->next = post;
                            break;
                        }

                        if (node->val < post->val) {
                            pre->next = node;
                            node->next = post;
                            break;
                        }

                        pre = post;
                        post = pre->next;
                    }
                }
            }
        }

        return sorted;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;

    ListNode a(5);
    ListNode b(3);
    ListNode c(10);

    a.next = &b;
    b.next = &c;

    ListNode *p = solve.insertionSortList(&a);
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;

    return 0;
}
