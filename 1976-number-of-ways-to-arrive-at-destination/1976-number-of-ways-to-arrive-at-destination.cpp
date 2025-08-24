class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : roads) 
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        int MOD = 1e9 + 7;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty())
        {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto id : graph[node]) 
            {
                int adjNode = id.first;
                long long adjW = id.second;
                if(time + adjW < dist[adjNode]) {
                    dist[adjNode] = time + adjW;
                    ways[adjNode] = ways[node];
                    pq.push({time + adjW, adjNode});
                }
                else if(time + adjW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};