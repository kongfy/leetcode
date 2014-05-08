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
    bool hasPathSum(TreeNode *root, int sum)
    {
        // protect
        if (!root) {
            return false;
        }
        
        // leaf
        if (!root->left && !root->right) {
            if (root->val == sum) {
                return true;
            }
        }

        // non-leaf
        int reminder = sum - root->val;
        return (hasPathSum(root->left, reminder) | hasPathSum(root->right, reminder));
    }
};

int main(int argc, char *argv[])
{
    
    return 0;
}
