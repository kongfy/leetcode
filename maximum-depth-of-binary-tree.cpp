#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode *root)
    {
        m_maxDepth = 0;

        travel(root, 1);

        return m_maxDepth;
    }

private:
    int m_maxDepth;

    void travel(TreeNode *node, int depth)
    {
        if (!node) {
            return;
        }

        if (depth > m_maxDepth) {
            m_maxDepth = depth;
        }

        travel(node->left, depth + 1);
        travel(node->right, depth + 1);
    }
};

int main(int argc, char *argv[])
{
    // seems need not to test...
    return 0;
}
