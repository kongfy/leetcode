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
    TreeNode *upsideDownBinaryTree(TreeNode *root)
    {
        TreeNode *p = root;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        TreeNode *ans = p;

        while (p) {
            TreeNode *t_left = p->right;
            TreeNode *t_right = p;
            TreeNode *q = p->left;
            ans = p;

            p->left = left;
            p->right = right;
            p = q;

            left = t_left;
            right = t_right;
        }

        return ans;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}
