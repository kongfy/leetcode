#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node) {
            return NULL;
        }

        if (_table.find(node->label) != _table.end()) {
            return _table[node->label];
        }

        UndirectedGraphNode *shadow = new UndirectedGraphNode(node->label);
        _table[node->label] = shadow;

        for (int i = 0; i < node->neighbors.size(); ++i) {
            UndirectedGraphNode *temp = cloneGraph(node->neighbors[i]);
            shadow->neighbors.push_back(temp);
        }

        return shadow;
    }

private:
    unordered_map<int, UndirectedGraphNode *> _table;
};

int main(int argc, char *argv[])
{

    return 0;
}
