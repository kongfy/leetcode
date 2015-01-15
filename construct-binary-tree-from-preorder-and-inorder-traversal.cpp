#include <vector>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildSub(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildSub(vector<int> &preorder, vector<int> &inorder, int pre_l, int pre_r, int in_l, int in_r)
    {
        if (pre_l > pre_r) {
            return NULL;
        }

        TreeNode *node = new TreeNode(preorder[pre_l]);

        if (pre_l == pre_r) {
            return node;
        }

        int index = find(inorder, preorder[pre_l], in_l, in_r);
        int left = index - in_l;

        node->left = buildSub(preorder, inorder, pre_l + 1, pre_l + left, in_l, index - 1);
        node->right = buildSub(preorder, inorder, pre_l + left + 1, pre_r, index + 1, in_r);

        return node;
    }

    int find(vector<int> &array, int target, int l, int r)
    {
        for (int i = l; i <= r; ++i) {
            if (target == array[i]) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
