class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<int , vector<int>, greater<int>> av_rooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used_rooms;
        vector<int> cnt(n, 0);

        for(int i = 0; i < n; i++)
        {
            av_rooms.push(i);
        }
        for(int i = 0; i < m; i++)
        {
            if(!used_rooms.empty() && meetings[i][0] >= used_rooms.top().first) {
                while(!used_rooms.empty() && meetings[i][0] >= used_rooms.top().first) 
                {
                    av_rooms.push(used_rooms.top().second);
                    used_rooms.pop();
                }
                used_rooms.push({meetings[i][1], av_rooms.top()});
            }
            else if(!av_rooms.empty()) {
                used_rooms.push({meetings[i][1], av_rooms.top()});
            }
            else {
                av_rooms.push(used_rooms.top().second);
                long long delay = used_rooms.top().first - meetings[i][0];
                used_rooms.pop();
                used_rooms.push({meetings[i][1]+delay, av_rooms.top()});
            }
            cnt[av_rooms.top()]++;
            av_rooms.pop();
        }
        int c = 0;
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(cnt[i] >= c) {
                c = cnt[i];
                ans = i;
            }
        }
        return ans;
    }
};