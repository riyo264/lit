class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int tr = INT_MAX;
        vector<int> ans;
        for(int i = 0; i < cost.size(); i++)
        {
            if(cost[i] < tr)
            {
                tr = cost[i];
            }
            ans.push_back(tr);
        }
        return ans;
    }
};