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
    bool isBalanced(TreeNode *root)
    {
        if (!root) {
            return true;
        }

        int height;
        return isBalancedNode(root, height);
    }

private:
    bool isBalancedNode(TreeNode *root, int &height)
    {
        int lheight = 0;
        int rheight = 0;
        bool lbalance = true, rbalance = true;

        if (root->left) {
            lbalance = isBalancedNode(root->left, lheight);
        }

        if (root->right) {
            rbalance = isBalancedNode(root->right, rheight);
        }

        height = std::max(lheight, rheight) + 1;
        return lbalance && rbalance && (std::abs(lheight - rheight) <= 1);
    }
};

int main(int argc, char *argv[])
{
    struct TreeNode node1(0), node2(0), node3(0), node4(0), node5(0), node6(0), node7(0), node8(0), node9(0), node10(0);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node3.left = &node5;
    node3.right = &node6;
    node4.left = &node7;
    node4.right = &node8;
    node5.right = &node9;
    node6.right = &node10;

    Solution solver;
    cout << solver.isBalanced(&node1) << endl;

    return 0;
}
