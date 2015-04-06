#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int> > ans;
        if (!root) return ans;

        stack<TreeNode *> s1, s2;
        s1.push(root);
        int level = -1;

        while (!s1.empty() || !s2.empty()) {
            level++;
            ans.push_back(vector<int> ());

            if (!s1.empty()) {
                while (!s1.empty()) {
                    TreeNode *node = s1.top();
                    s1.pop();
                    ans[level].push_back(node->val);
                    if (node->left) s2.push(node->left);
                    if (node->right) s2.push(node->right);
                }
            } else {
                while (!s2.empty()) {
                    TreeNode *node = s2.top();
                    s2.pop();
                    ans[level].push_back(node->val);
                    if (node->right) s1.push(node->right);
                    if (node->left) s1.push(node->left);
                }
            }
        }

        return ans;
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
