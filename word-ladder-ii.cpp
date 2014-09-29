#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <queue>


using namespace std;

typedef enum {
    Clean = 0,
    Pending,
    Completed,
} Status;

class Solution
{
    unordered_map<string, Status> nodes;
    unordered_map<string, int> pathLen;
    unordered_map<string, vector<string> > trace;
    queue<string> sq;

    void travel(const string &src, const string &dst)
    {
        vector<string> backTrace;

        if (nodes[dst] == Pending && pathLen[dst] > pathLen[src]) {
            backTrace = trace[dst];
            backTrace.push_back(src);
            trace[dst] = backTrace;
        }

        if (nodes[dst] == Clean) {
            sq.push(dst);
            backTrace.push_back(src);
            nodes[dst] = Pending;
            pathLen[dst] = pathLen[src] + 1;
            trace[dst] = backTrace;
        }
    }

    vector<vector<string> >pathTo(const string &dst)
    {
        vector<vector<string> >pathes;
        if (trace[dst].size() > 0) {
            for (string src : trace[dst]) {
                vector<vector<string> >subPathes = pathTo(src);
                for (vector<string> path : subPathes) {
                    path.push_back(dst);
                    pathes.push_back(path);
                }
            }
        } else {
            vector<string> path;
            path.push_back(dst);
            pathes.push_back(path);
        }

        return pathes;
    }

public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {
        if (start == end) {
            vector<string> path;
            vector<vector<string> > pathes;

            path.push_back(start);
            path.push_back(end);
            pathes.push_back(path);

            return pathes;
        }

        dict.insert(end);

        vector<string> emptyTrace;
        sq.push(start);
        nodes[start] = Pending;
        pathLen[start] = 1;
        trace[start] = emptyTrace;

        while (!sq.empty()) {
            string temp = sq.front();
            sq.pop();

            if (temp == end) {
                return pathTo(end);
            }

            for (int i = 0; i < temp.length(); ++i) {
                string copy = temp;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == temp[i]) continue;

                    copy[i] = c;

                    if (dict.count(copy) > 0) {
                        travel(temp, copy);
                    }
                }
            }
        }

        vector<vector<string> > pathes;
        return pathes;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    string start("hit");
    string end("cog");

    unordered_set<string> dict;

    string word;

    word = "hot";
    dict.insert(word);
    word = "dot";
    dict.insert(word);
    word = "dog";
    dict.insert(word);
    word = "lot";
    dict.insert(word);
    word = "log";
    dict.insert(word);

    vector<vector<string> > ans = solve.findLadders(start, end, dict);
    for (vector<string> path : ans) {
        for (string node : path) {
            cout << node << ' ';
        }
        cout << endl;
    }

    return 0;
}
