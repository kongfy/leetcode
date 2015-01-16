#include <vector>
#include <algorithm>

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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        vector<vector<int> > ans;

        traval(root, 0, ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    void traval(TreeNode *node, int level, vector<vector<int> > &ans)
    {
        if (!node) {
            return;
        }

        if (ans.size() < level + 1) {
            ans.push_back(vector<int>());
        }

        ans[level].push_back(node->val);
        traval(node->left, level + 1, ans);
        traval(node->right, level + 1, ans);
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
