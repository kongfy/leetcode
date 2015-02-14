#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct record
{
    struct TreeNode *p;
    bool flag;
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<struct record> s;
        vector<int> res;

        if (!root) {
            return res;
        }

        struct record first;
        first.p = root;
        first.flag = false;

        s.push(first);

        while (!s.empty()) {
            struct record &frame = s.top();

            if (frame.flag) {
                res.push_back(frame.p->val);
                s.pop();

                if (frame.p->right) {
                    struct record temp;

                    temp.p = frame.p->right;
                    temp.flag = false;
                    s.push(temp);
                }
            } else {
                // left child
                frame.flag = true;
                if (frame.p->left) {
                    struct record temp;

                    temp.p = frame.p->left;
                    temp.flag = false;
                    s.push(temp);
                }
            }
        }


        return res;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
