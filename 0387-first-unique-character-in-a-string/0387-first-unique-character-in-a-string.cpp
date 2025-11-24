class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> mpp;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i++)
        {
            if(mpp.count(s[i]) == 0) {
                mpp[s[i]] = {i, 0};
            }
            mpp[s[i]].second++;
        }
        for(auto x : mpp) {
            if(x.second.second == 1) {
                ans = min(ans, x.second.first);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};