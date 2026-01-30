class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        const long long INF = 1e18;
        int n = source.size();
        unordered_map<string, int> id;
        vector<string> nodes;

        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = nodes.size();
                nodes.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int M = nodes.size();
        vector<vector<long long>> dist(M, vector<long long>(M, INF));
        for (int i = 0; i < M; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = id[original[i]];
            int v = id[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 2: Floyd–Warshall (allows chaining on same interval)
        for (int k = 0; k < M; k++)
            for (int i = 0; i < M; i++)
                for (int j = 0; j < M; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        // Step 3: group rules by length
        unordered_map<int, vector<int>> byLen;
        for (int i = 0; i < original.size(); i++)
            byLen[original[i].size()].push_back(i);

        // Step 4: DP on positions
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (auto& [len, idxs] : byLen) {
                if (i + len > n) continue;

                string A = source.substr(i, len);
                string B = target.substr(i, len);

                if (!id.count(A) || !id.count(B)) continue;

                long long c = dist[id[A]][id[B]];
                if (c < INF && dp[i + len] < INF) {
                    dp[i] = min(dp[i], c + dp[i + len]);
                }
            }
        }

        return dp[0] == INF ? -1 : dp[0];
    }
};
