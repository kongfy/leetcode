#include <stdio.h>

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
    bool isSymmetric(TreeNode *root)
    {
        if (!root) {
            return true;
        }

        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) {
            return true;
        }

        if (left && right) {
            if (left->val != right->val) {
                return false;
            }

            return (isMirror(left->left, right->right) && isMirror(left->right, right->left));
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    TreeNode node1(1), node2(2), node3(2), node4(3), node5(4), node6(4), node7(3);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;

    Solution solution;

    printf("%d\n", solution.isSymmetric(&node1));
    
    return 0;
}

