#include <vector>
#include <queue>

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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        if (!root) return ans;

        queue<TreeNode *> q;
        int pre = 1, post = 0;
        int level = 0;
        q.push(root);
        ans.push_back(vector<int> ());

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            pre--;
            ans[level].push_back(node->val);

            if (node->left) {
                q.push(node->left);
                post++;
            }
            if (node->right) {
                q.push(node->right);
                post++;
            }

            if (!pre && post) {
                level++;
                ans.push_back(vector<int> ());

                pre = pre ^ post;
                post = pre ^ post;
                pre = pre ^ post;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
