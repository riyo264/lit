class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> final;
        int i = 0;
        int n = intervals.size();
        while(i < n && intervals[i][1] < newInterval[0])
        {
            final.push_back(intervals[i]);
            i++;
        }
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        final.push_back(newInterval);
        while(i<n){
            final.push_back(intervals[i]);
            i++;
        }
        return final;
    }
};