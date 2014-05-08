#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct RecordNode  
{
    bool in_path;
    int val;
    RecordNode *left, *right;
};

class Stack
{
public:
    bool isEmpty()
    {
        return _storage.empty();
    }

    void push(int x)
    {
        _storage.push_back(x);
    }
    
    int pop()
    {
        if (isEmpty()) {
            // dangours!
            return 0;
        }

        int tmp = _storage.back();
        _storage.pop_back();
        return tmp;
    }

    vector<int> copy()
    {
        return _storage;
    }

private:
    vector<int> _storage;
};

class Solution
{
public:
    ~Solution()
    {
        freeNode(_root);
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum)
    {
        _root = bulidPathSum(root, sum);

        generatePath(_root);
        return _storage;
    }

private:
    Stack _stack;
    RecordNode *_root;
    vector<vector<int> > _storage;

    void freeNode(RecordNode *root)
    {
        if (!root) {
            return;
        }

        freeNode(root->left);
        freeNode(root->right);

        free(root);
    }

    RecordNode* bulidPathSum(TreeNode *root, int sum)
    {
        // protect
        if (!root) {
            return NULL;
        }

        RecordNode *temp = (RecordNode *)malloc(sizeof(RecordNode));
        temp->val = root->val;
        
        // leaf
        if (!root->left && !root->right) {
            temp->left = NULL;
            temp->right = NULL;
            temp->in_path = false;
            
            if (root->val == sum) {
                temp->in_path = true;
            }
            return temp;
        }

        // non-leaf
        int reminder = sum - root->val;
        temp->left = bulidPathSum(root->left, reminder);
        temp->right = bulidPathSum(root->right, reminder);
        temp->in_path = false;

        if (temp->left) {
            temp->in_path |= temp->left->in_path;
        }

        if (temp->right) {
            temp->in_path |= temp->right->in_path;
        }
        
        return temp;
    }

    void generatePath(RecordNode *root)
    {
        if (!root) {
            return;
        }

        if (!root->in_path) {
            return;
        }

        _stack.push(root->val);

        // leaf
        if (!root->left && !root->right) {
            _storage.push_back(_stack.copy());
        }

        // non-leaf
        generatePath(root->left);
        generatePath(root->right);

        _stack.pop();
        return;
    }

};

int main(int argc, char *argv[])
{
    TreeNode node1(1), node2(2);
    node1.left = &node2;

    Solution solution;

    vector<vector<int> > result = solution.pathSum(&node1, 3);

    
    
    return 0;
}
