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

struct record
{
    struct TreeNode *p;
    int flag;
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<struct record> s;
        vector<int> result;

        if (!root) {
            return result;
        }

        struct record first;
        first.p = root;
        first.flag = 0;

        s.push(first);

        while (!s.empty()) {
            struct record &frame = s.top();
            frame.flag++;

            if (1 == frame.flag) {
                // left child
                if (frame.p->left) {
                    struct record temp;

                    temp.p = frame.p->left;
                    temp.flag = 0;
                    s.push(temp);
                }
                continue;
            }

            if (2 == frame.flag) {
                // right child
                if (frame.p->right) {
                    struct record temp;

                    temp.p = frame.p->right;
                    temp.flag = 0;
                    s.push(temp);
                }
                continue;
            }

            if (3 == frame.flag) {
                // root
                result.push_back(frame.p->val);
                s.pop();
                continue;
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
    vector<int> result = solution.postorderTraversal(&node1);


    for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}
