#include <bits/stdc++.h>
using namespace std;

struct Gain {
    double delta;
    int pass, total;
    bool operator<(const Gain &other) const {
        return delta < other.delta;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Gain> pq;
        for (auto &c : classes) {
            int pass = c[0], total = c[1];
            double delta = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({delta, pass, total});
        }
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int pass = top.pass + 1;
            int total = top.total + 1;
            double delta = ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
            pq.push({delta, pass, total});
        }
        double result = 0.0;
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            result += (double)t.pass / t.total;
        }
        return result / classes.size();
    }
};
