#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <queue>


using namespace std;

class Solution
{
    unordered_map<string, int> trace;
    queue<string> sq;

    void travel(const string &src, const string &dst)
    {
        sq.push(dst);
        trace[dst] = trace[src] + 1;
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        if (start == end) {
            return 0;
        }

        dict.insert(end);

        sq.push(start);
        trace[start] = 1;

        while (!sq.empty()) {
            string temp = sq.front();
            sq.pop();

            for (int i = 0; i < temp.length(); ++i) {
                string copy = temp;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == temp[i]) continue;

                    copy[i] = c;

                    if (dict.count(copy) > 0 && trace.count(copy) == 0) {
                        travel(temp, copy);

                        if (copy == end) {
                            return trace[end];
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution solve;
    string start("hot");
    string end("cog");

    unordered_set<string> dict;

    string word;

    word = "hot";
    dict.insert(word);
    word = "dog";
    dict.insert(word);
    word = "dog";
    dict.insert(word);
    word = "tot";
    dict.insert(word);
    word = "hog";
    dict.insert(word);
    word = "hop";
    dict.insert(word);
    word = "pot";
    dict.insert(word);
    word = "dot";
    dict.insert(word);

    cout << solve.ladderLength(start, end, dict) << endl;

    return 0;
}
