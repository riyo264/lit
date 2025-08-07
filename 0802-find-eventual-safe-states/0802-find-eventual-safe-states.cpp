class Solution {
private:
    bool Cycle(int node, vector<int>& vis, vector<int>& path_vis, vector<vector<int>>& pre, vector<int>& check) {
        vis[node] = 1;
        path_vis[node] = 1;

        for(auto it : pre[node])
        {
            if(vis[it] == 0) {
                if(Cycle(it, vis, path_vis, pre, check) == true) {
                    check[it] = 0;
                    return true;
                }
            }
            else if(path_vis[it] == 1) {
                check[it] = 0;
                return true;
            }
        }

        check[node] = 1;
        path_vis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numCourses = graph.size();
        vector<int> vis(numCourses, 0);
        vector<int> path_vis(numCourses, 0);
        vector<int> ans;
        vector<int> check(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == 0) {
                Cycle(i, vis, path_vis, graph, check);
            }
        }
        for(int i =0; i < numCourses; i++)
        {
            if(check[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};