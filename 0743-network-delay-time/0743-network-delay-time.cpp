class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto &it : times)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<int> time(n+1, 1e9);
        time[k] = 0;
        pq.push({0, k});
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto id : graph[node]) 
            {
                int adjNode = id.first;
                int w = id.second;
                if(dist + w < time[adjNode]) {
                    time[adjNode] = dist + w;
                    pq.push({dist + w, adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (time[i] == 1e9) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};