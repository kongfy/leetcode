#include <iostream>

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
    bool isValidBST(TreeNode *root)
    {
        if (!root) {
            return true;
        }

        int min, max;
        return isValidBSTSub(root, min, max);
    }

private:
    bool isValidBSTSub(TreeNode *root, int &min, int &max)
    {
        int l_min, l_max, r_min, r_max;

        if (root->left) {
            if (isValidBSTSub(root->left, l_min, l_max)) {
                if (root->val <= l_max) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            l_min = root->val;
        }

        if (root->right) {
            if (isValidBSTSub(root->right, r_min, r_max)) {
                if (root->val >= r_min) {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            r_max = root->val;
        }

        min = l_min;
        max = r_max;

        return true;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
