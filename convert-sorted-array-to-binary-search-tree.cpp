#include <iostream>
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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return BST(num, 0, num.size());
    }

private:
    TreeNode *BST(vector<int> &num, int l, int r)
    {
        if (l >= r) {
            return NULL;
        }

        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = BST(num, l, mid);
        node->right = BST(num, mid + 1, r);

        return node;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
