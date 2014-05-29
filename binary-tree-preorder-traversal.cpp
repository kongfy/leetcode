#include <vector>
#include <stack>
#include <iostream>


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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> result;

        if (!root) {
            return result;
        }

        s.push(root);

        while (!s.empty()) {
            TreeNode *p = s.top();

            result.push_back(p->val);
            s.pop();
            if (p->right) {
                s.push(p->right);
            }

            if (p->left) {
                s.push(p->left);
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    TreeNode node1(1), node2(2), node3(3);
    node1.right = &node2;
    node2.left = &node3;

    Solution solution;
    vector<int> result = solution.preorderTraversal(&node1);


    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
