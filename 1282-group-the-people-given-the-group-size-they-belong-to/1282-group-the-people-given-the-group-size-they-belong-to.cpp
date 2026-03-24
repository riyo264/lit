class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        map<int, vector<int>> mpp;
        int min_size = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            min_size = min(min_size, groupSizes[i]);
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto& x : mpp) 
        {
                vector<int> ind = x.second;
                while(!ind.empty()) {
                    vector<int> temp;
                    for(int i = 0; i < x.first; i++)
                    {
                        temp.push_back(ind[0]);
                        ind.erase(ind.begin());
                    }
                    ans.push_back(temp);
                }
                min_size = x.first;
        }
        return ans;
    }
};