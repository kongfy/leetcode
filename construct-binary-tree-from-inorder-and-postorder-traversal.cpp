#include <vector>

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildSub(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode *buildSub(vector<int> &postorder, vector<int> &inorder, int post_l, int post_r, int in_l, int in_r)
    {
        if (post_l > post_r) {
            return NULL;
        }

        TreeNode *node = new TreeNode(postorder[post_r]);

        if (post_l == post_r) {
            return node;
        }

        int index = find(inorder, postorder[post_r], in_l, in_r);
        int left = index - in_l;

        node->left = buildSub(postorder, inorder, post_l, post_l + left - 1, in_l, index - 1);
        node->right = buildSub(postorder, inorder, post_l + left, post_r - 1, index + 1, in_r);

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
