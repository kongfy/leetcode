#include <vector>
#include <iostream>

using namespace std;

enum Status {
    CLEAN = 0,
    TRAVELING,
    DONE,
};

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> > &prerequisites)
    {
        vector<int> order;
        vector<vector<int> > g = vector<vector<int> > (numCourses, vector<int> ());
        for (auto &edge : prerequisites) {
            int s = edge.first;
            int t = edge.second;

            g[s].push_back(t);
        }

        vector<Status> color(numCourses, CLEAN);
        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == CLEAN) {
                if (!travel(i, color, g, order)) {
                    return {};
                }
            }
        }

        return order;
    }

    bool travel(int v, vector<Status> &color, vector<vector<int> > &g, vector<int> &order)
    {
        color[v] = TRAVELING;

        for (int u : g[v]) {
            if (color[u] == CLEAN) {
                if (!travel(u, color, g, order)) {
                    return false;
                }
            } else if (color[u] == TRAVELING) {
                // not cycle free
                return false;
            } else {
                // Done
            }
        }

        color[v] = DONE;
        order.push_back(v);
        return true;
    }
};

int main(int argc, char *argv[])
{
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));

    Solution solver;
    vector<int> order = solver.findOrder(4, prerequisites);

    for (int v : order) {
        cout << v << endl;
    }

    return 0;
}
