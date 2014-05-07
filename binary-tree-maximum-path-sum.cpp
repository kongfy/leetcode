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
    int maxPathSum(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        
        ans = root->val;
        oneSideMaxPathSum(root);
        return ans;
    }

private:
    inline int max(int a, int b)
    {
        if (a > b) {
            return a;
        }
        return b;
    }
    
    int oneSideMaxPathSum(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        int left_sum = oneSideMaxPathSum(root->left);
        int right_sum = oneSideMaxPathSum(root->right);

        // update ans
        ans = max(ans, root->val);
        ans = max(ans, root->val + left_sum);
        ans = max(ans, root->val + right_sum);
        ans = max(ans, root->val + left_sum + right_sum);

        int sum = root->val;
        if (left_sum > right_sum) {
            sum = max(sum, left_sum + sum);
        } else {
            sum = max(sum, right_sum + sum);
        }
        
        return sum;
    }

    int ans;
};

int main(int argc, char *argv[])
{
    TreeNode node1(-3), node2(2), node3(-3);
    node1.left = &node2;
    node1.right = &node3;

    Solution solution;
    printf("%d\n", solution.maxPathSum(&node1));
    
    return 0;
}
