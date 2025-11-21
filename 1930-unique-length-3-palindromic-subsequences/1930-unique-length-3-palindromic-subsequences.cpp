class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> mpp;
        int n = s.size();
        for(int i = 0; i < n; i++) 
        {
            mpp[s[i]]++;
        }
        int ans = 0;
        for(auto x : mpp) {
            if(x.second > 1) {
                int l = 0;
                while(s[l] != x.first) {
                    l++;
                }
                int r = n-1;
                while(s[r] != x.first) {
                    r--;
                }
                unordered_map<char, int> mpp1;
                for(int i = l+1; i < r; i++)
                {
                    if(mpp1[s[i]] > 0) {
                        continue;
                    }
                    else {
                        ans++;
                        mpp1[s[i]]++;
                    }
                }
            }
        }
        return ans;
    }
};