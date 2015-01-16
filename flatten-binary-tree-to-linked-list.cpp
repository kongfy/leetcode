#include <iostream>

using namespace std;

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
    void flatten(TreeNode *root)
    {
        flattenSub(root);
    }

private:
    TreeNode *flattenSub(TreeNode *node)
    {
        if (!node) {
            return NULL;
        }

        TreeNode *left = flattenSub(node->left);
        TreeNode *right = flattenSub(node->right);

        if (left) {
            left->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }

        if (right) {
            return right;
        } else if (left) {
            return left;
        } else {
            return node;
        }
    }
};

int main(int argc, char *argv[])
{
    TreeNode a(1), b(2);
    a.right = &b;

    Solution solver;
    solver.flatten(&a);

    return 0;
}
