#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <queue>


using namespace std;

class Solution
{
    unordered_set<string> map;
    unordered_map<string, string> trace;
    queue<string> sq;

    static string mark;

    bool isConnected(const string &a, const string &b)
    {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
        }

        return count == 1;
    }

    void travel(const string &src, const string &dst)
    {
        map.insert(dst);
        sq.push(dst);
        trace[dst] = src;
    }

    bool isTraveled(const string &a)
    {
        const unordered_set<string>::iterator search = map.find(a);
        return search != map.end();
    }

    int pathLengthTo(const string &a)
    {
        int length = 0;

        string temp = a;
        do {
            cout << temp << endl;
            length ++;
            temp = trace[temp];
        } while (temp != mark);

        return length;
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        if (start == end) {
            return 0;
        }

        dict.insert(start);
        dict.insert(end);

        travel(mark, start);

        while (!sq.empty()) {
            string temp = sq.front();
            sq.pop();

            for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++) {
                if (!isTraveled(*iter) && isConnected(temp, *iter)) {
                    travel(temp, *iter);

                    if (*iter == end) {
                        // find it
                        return pathLengthTo(end);
                    }
                }
            }
        }

        return 0;
    }
};

string Solution::mark = "";

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
