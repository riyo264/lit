class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        stable_sort(g.begin(), g.end());
        stable_sort(s.begin(), s.end());
        int l = 0;
        int r = 0;
        int cnt = 0;
        while(l < g.size() && r < s.size())
        {
            if(s[r] < g[l])
            {
                r++;
            }
            else if(s[r] >= g[l])
            {
                cnt++;
                r++;
                l++;
            }
        } 
        return cnt;
    }
};