#include <vector>
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0) {
            return vector<TreeNode *> (1, NULL);
        }

        vector<vector<vector<TreeNode *> > > route(n, vector<vector<TreeNode *> > (n, vector<TreeNode *>()));

        // init
        for (int i = 0; i < n; ++i) {
            route[i][i].push_back(new TreeNode(i + 1));
        }

        // dp
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    if (k == i) {
                        for (TreeNode *right : route[i + 1][j]) {
                            TreeNode *node = new TreeNode(k + 1);
                            node->right = right;
                            route[i][j].push_back(node);
                        }
                    } else if (k == j) {
                        for (TreeNode *left : route[i][j - 1]) {
                            TreeNode *node = new TreeNode(k + 1);
                            node->left = left;
                            route[i][j].push_back(node);
                        }
                    } else {
                        for (TreeNode *left : route[i][k - 1]) {
                            for (TreeNode *right : route[k + 1][j]) {
                                TreeNode *node = new TreeNode(k + 1);
                                node->left = left;
                                node->right = right;
                                route[i][j].push_back(node);
                            }
                        }
                    }
                }
            }
        }

        return route[0][n - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution solver;


    return 0;
}
