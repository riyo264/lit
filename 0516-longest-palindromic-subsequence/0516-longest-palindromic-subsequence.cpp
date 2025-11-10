class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        // for(int i = 0; i <= n; i++)
        // {
        //     prev[0] = 0;
        // }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s1[i-1] == s[j-1]) {
                    cur[j] = 1 + prev[j-1];
                }
                else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
};