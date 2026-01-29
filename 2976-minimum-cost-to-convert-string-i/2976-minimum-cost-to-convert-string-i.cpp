class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> G(26);
        int n = original.size();
        for(int i = 0; i < n; i++) 
        {
            int o = original[i] - 'a';
            int c = changed[i] - 'a';
            G[o].push_back({c, cost[i]});
        }
        long long price = 0;
            vector<vector<int>> dist(26, vector<int>(26, 1e9));
            for (int src = 0; src < 26; src++) {
                priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
                dist[src][src] = 0;
                pq.push({0, src});
                while (!pq.empty()) {
                    auto [d, u] = pq.top();
                    pq.pop();
                    if (d > dist[src][u]) continue;
                    for (auto &[v, w] : G[u]) {
                        if (dist[src][v] > d + w) {
                            dist[src][v] = d + w;
                            pq.push({dist[src][v], v});
                        }
                    }
                }
            }
        for(int i = 0; i < source.size(); i++) 
        {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if(s == t) continue;
            if(dist[s][t] == 1e9) {
                return -1;
            }
            else {
                price += dist[s][t];
            }
        }
        return price;
    }
};