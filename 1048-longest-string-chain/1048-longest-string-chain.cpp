class Solution {
public:
    bool compare(string &s, string &t) {
    if (s.size() != t.size() + 1) return false;

    int i = 0, j = 0;
    bool skipped = false;

    while (i < s.size()) {
        if (j < t.size() && s[i] == t[j]) {
            i++; j++;
        } else {
            if (skipped) return false;
            skipped = true;
            i++; 
        }
    }
    return true;
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(compare(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};