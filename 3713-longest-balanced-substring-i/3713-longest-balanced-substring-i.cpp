class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int l = 0;
            unordered_map<char, int> freq;
            for(int j = i; j < n; j++)
            {
                freq[s[j]]++;
                l++;
                int c = freq[s[j]];
                bool flag = true;
                for(auto x : freq) {
                    if(x.second != c) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans = max(l, ans);
                }
            }
        }
        return ans;
    }
};