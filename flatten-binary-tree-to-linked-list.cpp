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
    void flattenSub(TreeNode *node)
    {
        if (!node) {
            return;
        }

        TreeNode *left = node->left;
        TreeNode *right = node->right;

        if (!_tail) {
            _tail = node;
            node->left = NULL;
            node->right = NULL;
        } else {
            _tail->right = node;
            _tail = node;
            node->left = NULL;
            node->right = NULL;
        }

        flattenSub(left);
        flattenSub(right);
    }

    TreeNode *_tail = NULL;
};

int main(int argc, char *argv[])
{
    TreeNode a(1), b(2);
    a.right = &b;

    Solution solver;
    solver.flatten(&a);

    return 0;
}
