class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string og = s;
        reverse(s.begin(), s.end());
        vector<int> prev(n+1, 0), cur(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(og[i-1] == s[j-1]) {
                    cur[j] = 1 + prev[j-1];
                }
                else {
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return n - prev[n];
    }
};