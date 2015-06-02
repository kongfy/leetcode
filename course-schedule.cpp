#include <vector>

using namespace std;

enum Status {
    CLEAN = 0,
    TRAVELING,
    DONE,
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int> > &prerequisites)
    {
        vector<vector<int> > g = vector<vector<int> > (numCourses, vector<int> ());
        for (auto &edge : prerequisites) {
            int s = edge.first;
            int t = edge.second;

            g[s].push_back(t);
        }

        vector<Status> color(numCourses, CLEAN);
        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == CLEAN) {
                if (!travel(i, color, g)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool travel(int v, vector<Status> &color, vector<vector<int> > &g)
    {
        color[v] = TRAVELING;

        for (int u : g[v]) {
            if (color[u] == CLEAN) {
                if (!travel(u, color, g)) {
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
        return true;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
