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
    void recoverTree(TreeNode *root)
    {
        inTravel(root);

        if (!_t2) {
            _t2 = _p;
        }

        int temp = _t->val;
        _t->val = _t2->val;
        _t2->val = temp;
    }

private:
    void inTravel(TreeNode *root)
    {
        if (!root) {
            return;
        }

        inTravel(root->right);
        visit(root);
        inTravel(root->left);
    }

    void visit(TreeNode *root)
    {
        _q = _p;
        _p = root;

        if (!_t) {
            if (_q && _q->val < _p->val) {
                _t = _q;
            }
            return;
        }

        if (!_t2) {
            if (_q && _p->val <= _t->val) {
                _t2 = _q;
            }
        }
    }

    TreeNode *_p, *_q, *_t, *_t2;
};

int main(int argc, char *argv[])
{

    return 0;
}
