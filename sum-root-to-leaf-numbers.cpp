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
    int sumNumbers(TreeNode *root)
    {
        _sum = 0;

        sumTree(root, 0);

        return _sum;
    }

private:
    void sumTree(TreeNode *node, int sum)
    {
        if (!node) {
            return;
        }

        sum *= 10;
        sum += node->val;

        if (!node->left && !node->right) {
            // leaf
            _sum += sum;
            return;
        }

        sumTree(node->left, sum);
        sumTree(node->right, sum);
    }

    int _sum = 0;
};

int main(int argc, char *argv[])
{

    return 0;
}
