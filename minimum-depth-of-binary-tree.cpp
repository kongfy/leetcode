struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        return minDepthNode(root, 1);
    }

private:
    int minDepthNode(TreeNode *root, int dep)
    {
        if (!root) {
            return 0;
        }

        if (!root->left && !root->right) {
            return dep;
        }

        int dep_left = minDepthNode(root->left, dep + 1);
        int dep_right = minDepthNode(root->right, dep + 1);

        int ans = ~(1 << 31);
        if (dep_left) {
            ans = std::min(ans, dep_left);
        }

        if (dep_right) {
            ans = std::min(ans, dep_right);
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
