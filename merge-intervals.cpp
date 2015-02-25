#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct
{
    bool operator() (Interval a, Interval b)
    {
        return a.start < b.start;
    }
} customLess;

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), customLess);

        vector<Interval> res;

        int n = intervals.size();
        if (n == 0) return res;

        int l = intervals[0].start, r = intervals[0].end;
        for (int i = 0; i < n; ++i) {
            if (intervals[i].start > r) {
                res.push_back(Interval(l, r));

                l = intervals[i].start;
                r = intervals[i].end;
            } else {
                r = max(r, intervals[i].end);
            }
        }

        res.push_back(Interval(l, r));
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<Interval> res;
    res.push_back(Interval(15, 18));
    res.push_back(Interval(2, 6));
    res.push_back(Interval(1, 3));
    res.push_back(Interval(8, 10));


    Solution solver;

    res = solver.merge(res);
    for (Interval &interval : res) {
        cout << interval.start << ' ' << interval.end << endl;
    }

    return 0;
}
