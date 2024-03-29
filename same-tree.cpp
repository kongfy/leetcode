#include <cstdio>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q) {
            if (!p && !q) {
                return true;
            }
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        if (!p->left && !p->right && !q->left && !q->right) {
            if (p->val == q->val) {
                return true;
            }
        }
        
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
