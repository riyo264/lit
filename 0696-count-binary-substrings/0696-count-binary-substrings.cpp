class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int zeroes = 0;
        int ones = 0;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1') {
                ones++;
                if(i+1 < n && s[i+1] == '0') {
                    ans += min(ones, zeroes);
                    zeroes = 0;
                }
            }
            else {
                zeroes++;
                if(i+1 < n && s[i+1] == '1') {
                    ans += min(ones, zeroes);
                    ones = 0;
                }
            }
        }
        ans += min(ones, zeroes);
        return ans;
    }
};