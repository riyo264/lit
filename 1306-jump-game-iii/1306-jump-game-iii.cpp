class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++) {
            if(i + arr[i] < n) {
                graph[i].push_back(i+arr[i]);
            }
            if(i - arr[i] >= 0) {
                graph[i].push_back(i-arr[i]);
            }
        }
        vector<int> vis(n, 0);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            if(arr[i] == 0) {
                return true;
            }
            vis[i] = 1;
            for(int x : graph[i]) {
                if(vis[x] != 1) {
                    q.push(x);
                    vis[x] = 1;
                }
            }
        }
        return false;
    }
};