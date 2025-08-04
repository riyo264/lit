class Solution {
private:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis) {
        vis[start] = 0;
        queue<int> Q;
        Q.push(start);
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for(int it : graph[node])
            {
                if(vis[it] == -1) {
                    vis[it] = !vis[node];
                    Q.push(it);
                }
                else if(vis[it] == vis[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i = 0; i < vis.size(); i++)
        {
            if(vis[i] == -1) {
                if(bfs(i, graph, vis) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};