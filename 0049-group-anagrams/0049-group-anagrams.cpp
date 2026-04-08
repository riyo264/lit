class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp = strs;
        for(int i = 0; i < temp.size(); i++)
        {
            sort(temp[i].begin(), temp[i].end());
        }
        unordered_map<string, vector<int>> mpp;
        for(int i = 0; i < temp.size(); i++)
        {
            mpp[temp[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto x : mpp) {
            vector<string> s;
            for(int i : x.second) {
                s.push_back(strs[i]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};