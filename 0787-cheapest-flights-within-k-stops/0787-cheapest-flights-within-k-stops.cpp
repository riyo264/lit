class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : flights)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> cost(n, 1e9);
        cost[src] = 0;
        q.push({0, {src, 0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int Cost = it.second.second;
            if(stops > k) {
                continue;
            }
            if(node == dst) {
                continue;
            }
            for(auto idx : graph[node]) 
            {
                int adjNode = idx.first;
                int adjCost = idx.second;

                if(Cost + adjCost < cost[adjNode] && stops <= k) {
                    cost[adjNode] = Cost + adjCost;
                    q.push({stops+1, {adjNode, Cost+adjCost}});
                }
            }
        }
        if(cost[dst] == 1e9) {
            return -1;
        }
        return cost[dst];
    }
};