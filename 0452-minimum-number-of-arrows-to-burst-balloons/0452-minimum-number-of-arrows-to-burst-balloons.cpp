class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b .first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        pair<int, int> intervals[100000];
        for(int i = 0; i < n; i++)
        {
            intervals[i].first = points[i][0];
            intervals[i].second = points[i][1];
        }
        sort(intervals, intervals+n, comp);
        int arrows = 1;
        int prev = intervals[0].second;
        for(int i = 1; i < n; i++) {
            if(intervals[i].first > prev) {
                arrows++;
                prev = intervals[i].second;
            }
            prev = min(prev, intervals[i].second);
        }
        return arrows;
    }
};