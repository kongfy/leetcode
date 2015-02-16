struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (!root) return;

        TreeLinkNode *nextLevel = NULL, *temp = NULL;
        while (root) {
            if (root->left) {
                if (!temp) {
                    nextLevel = temp = root->left;
                } else {
                    temp->next = root->left;
                    temp = root->left;
                }
            }

            if (root->right) {
                if (!temp) {
                    nextLevel = temp = root->right;
                } else {
                    temp->next = root->right;
                    temp = root->right;
                }
            }

            root = root->next;
        }

        connect(nextLevel);
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
