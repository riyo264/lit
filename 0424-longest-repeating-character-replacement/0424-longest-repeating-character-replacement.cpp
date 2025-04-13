class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxf = 0;
        int maxlen = 0;
        unordered_map <char, int> mpp;
        while(r < s.size())
        {
            mpp[s[r]]++;
            maxf = max(maxf, mpp[s[r]]);
            if((r-l+1)-maxf > k)
            {
                mpp[s[l]]--;
                l++;
            }
            else if((r-l+1)-maxf <= k)
            {
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};