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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        travel(root, ans, 0);

        return ans;
    }

private:
    void travel(TreeNode *root, vector<int> &ans, int dep)
    {
        if (!root) {
            return;
        }

        if (dep + 1 > ans.size()) {
            ans.push_back(root->val);
        } else {
            ans[dep] = root->val;
        }

        travel(root->left, ans, dep + 1);
        travel(root->right, ans, dep + 1);
    }
};
