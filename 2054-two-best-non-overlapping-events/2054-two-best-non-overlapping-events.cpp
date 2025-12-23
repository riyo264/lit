class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> suffix(n);
        suffix[n-1] = events[n-1][2];
        for(int i = n-2; i >= 0; i--) {
            suffix[i] = max(events[i][2], suffix[i+1]);
        }
        int value = 0;
        for(int i = 0; i < n; i++)
        {
            value = max(value, events[i][2]);
            int l = i+1;
            int h = n-1;
            int end = events[i][1];
            int ind = INT_MAX;
            while(l <= h) 
            {
                int mid = (l+h)/2;
                if(events[mid][0] > end) {
                    ind = min(ind, mid);
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            if(ind != INT_MAX) {
                value = max(value, events[i][2] + suffix[ind]);
            }
        }
        return value;
    }
};