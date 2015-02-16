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

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        while(root) {
            _storage.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !_storage.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        if (_storage.empty()) return -1;

        TreeNode *node = _storage.top();
        _storage.pop();

        TreeNode *p = node->right;
        while (p) {
            _storage.push(p);
            p = p->left;
        }

        return node->val;
    }

private:
    stack<TreeNode *> _storage;
};

int main(int argc, char *argv[])
{
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5);

    node2.left = &node1;
    node2.right = &node5;
    node5.left = &node3;
    node3.right = &node4;

    BSTIterator i = BSTIterator(&node2);
    while (i.hasNext()) cout << i.next() << ' ';
    cout << endl;

    return 0;
}
