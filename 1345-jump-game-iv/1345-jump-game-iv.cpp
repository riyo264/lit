class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> ind;
        for(int i = 0; i < n; i++)
        {
            ind[nums[i]].push_back(i);
        }
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        int jumps = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int id = q.front();
                q.pop();
                if(id == n-1) {
                    return jumps;
                }
                if(id + 1 < n && vis[id+1] == 0) {
                    vis[id + 1] = 1;
                    q.push(id+1);
                }
                if(id - 1 >= 0 && vis[id-1] == 0) {
                    vis[id - 1] = 1;
                    q.push(id-1);
                }
                for(int x : ind[nums[id]]) {
                    if(vis[x] == 0) {
                        vis[x] = 1;
                        q.push(x);
                    }
                }
                ind[nums[id]].clear();
            }
            jumps++;
        }
        return 0;
    }
};