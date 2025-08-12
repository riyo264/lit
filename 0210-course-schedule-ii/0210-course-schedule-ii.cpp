class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto it : prerequisites)
        {
            graph[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < graph.size(); i++)
        {
            for(auto it : graph[i])
            {
                indegree[it]++;
            }
        }
        queue<int> Q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) {
                Q.push(i);
            }
        }
        vector<int> topo;
        while(!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            topo.push_back(node);

            for(auto it : graph[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) {
                    Q.push(it);
                }
            }
        }
        vector<int> empty;
        reverse(topo.begin(), topo.end());
        if(numCourses == topo.size()) return topo;
        return empty;
    }
};