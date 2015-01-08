#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        _list = head;

        int len = lengthOfList(head);
        return BST(0, len);
    }

private:
    ListNode *_list;

    int lengthOfList(ListNode *head)
    {
        ListNode *p = head;
        int len = 0;

        while (p) {
            len++;
            p = p->next;
        }

        return len;
    }

    TreeNode *BST(int l, int r)
    {
        if (l >= r) {
            return NULL;
        }

        int mid = (l + r) / 2;
        TreeNode *left = BST(l, mid);

        TreeNode *node = new TreeNode(_list->val);
        _list = _list->next;

        TreeNode *right = BST(mid + 1, r);

        node->left = left;
        node->right = right;
        return node;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1), node2(2), node3(3);
    node1.next = &node2;
    node2.next = &node3;

    Solution solver;

    solver.sortedListToBST(&node1);
    return 0;
}
