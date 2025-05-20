class Solution {
public:
   static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

 int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        pair<int, int> event[100000];
        int event_end = 0;
        for(int i = 0; i < n; i++)
        {
            event[i].first = intervals[i][0];
            event[i].second = intervals[i][1]; 
        }
        sort(event, event + n, comp);
        int cnt = 0;
        event_end = event[0].second;
        for(int i = 1; i < n; i++){
            if(event[i].first >= event_end)
            {
                event_end = event[i].second;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};