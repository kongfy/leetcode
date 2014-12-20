#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;

        travel(root, 1, ans);

        return ans;
    }

private:
    void travel(TreeNode *node, int level, vector<vector <int> > &ans)
    {
        if (!node) {
            return;
        }

        vector<int> temp;
        if (level > ans.size()) {
            ans.push_back(temp);
        }

        if (level & 1) {
            ans[level - 1].push_back(node->val);
        } else {
            ans[level - 1].insert(ans[level - 1].begin(), node->val);
        }

        travel(node->left, level + 1, ans);
        travel(node->right, level + 1, ans);
    }
};

int main(int argc, char *argv[])
{
    Solution solver;

    TreeNode node0(3), node1(9), node2(20), node3(15), node4(7);

    node0.left = &node1;
    node0.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    vector<vector <int> > ans = solver.zigzagLevelOrder(&node0);

    for (vector<int> row : ans) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }

    return 0;
}
